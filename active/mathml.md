
```h
// dom/mathml/MathMLAnchorElement.h

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_dom_MathMLAnchorElement_h
#define mozilla_dom_MathMLAnchorElement_h

#include "MathMLElement.h"
#include "mozilla/dom/Link.h"
#include "nsDOMTokenList.h"

namespace mozilla::dom {

// FIXME: We should also inherit from Link once we migrate link behavior from
// MathMLElement. Since MathMLElement already inherits from Link, we need to
// prevent diamond inheritance for now.
class MathMLAnchorElement final : public MathMLElement {
 public:
  explicit MathMLAnchorElement(
      already_AddRefed<mozilla::dom::NodeInfo>&& aNodeInfo);

  NS_IMPL_FROMNODE_HELPER(MathMLAnchorElement, IsMathMLElement())

  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(MathMLAnchorElement, MathMLElement)

  // nsISupports
  NS_DECL_ISUPPORTS_INHERITED

  void GetHref(nsAString& aHref, ErrorResult& aRv) const {
    GetAttr(nsGkAtoms::href, aHref);
  }
  
  void SetHref(const nsAString& aHref, ErrorResult& aRv) {
    SetAttr(nsGkAtoms::href, aHref, aRv);
  }

  void GetTarget(nsAString& aValue) const {
    if (!GetAttr(nsGkAtoms::target, aValue)) {
      GetBaseTarget(aValue);
    }
  }
  void SetTarget(const nsAString& aValue, ErrorResult& aRv) {
    SetAttr(nsGkAtoms::target, aValue, aRv);
  }

  void GetHreflang(DOMString& aValue) const {
    GetAttr(nsGkAtoms::hreflang, aValue);
  }
  void SetHreflang(const nsAString& aValue, mozilla::ErrorResult& rv) {
    SetAttr(nsGkAtoms::hreflang, aValue, rv);
  }
  void GetType(DOMString& aValue) const { GetAttr(nsGkAtoms::type, aValue); }
  void SetType(const nsAString& aValue, mozilla::ErrorResult& rv) {
    SetAttr(nsGkAtoms::type, aValue, rv);
  }

  void GetBaseTarget(nsAString& aValue) const;

  void GetLinkTargetImpl(nsAString& aTarget) override;

  bool HasHref() const { return HasAttr(nsGkAtoms::href); }
  already_AddRefed<nsIURI> GetHrefURI() const override;

  // nsINode interface methods
  void GetEventTargetParent(mozilla::EventChainPreVisitor& aVisitor) override;
  MOZ_CAN_RUN_SCRIPT
  nsresult PostHandleEvent(mozilla::EventChainPostVisitor& aVisitor) override;
  nsresult Clone(dom::NodeInfo*, nsINode** aResult) const override;

  Focusable IsFocusableWithoutStyle(IsFocusableFlags aFlags) override;

  // nsIContent
  nsresult BindToTree(BindContext& aContext, nsINode& aParent) override;
  void UnbindFromTree(UnbindContext& aContext) override;
  void AfterSetAttr(int32_t aNamespaceID, nsAtom* aName,
                    const nsAttrValue* aValue, const nsAttrValue* aOldValue,
                    nsIPrincipal* aMaybeScriptedPrincipal,
                    bool aNotify) override;

 protected:
  virtual ~MathMLAnchorElement() = default;
  JSObject* WrapNode(JSContext* aCx,
                     JS::Handle<JSObject*> aGivenProto) override;

  RefPtr<nsDOMTokenList> mRelList;
};

}  // namespace mozilla::dom

#endif


```

```cpp
// dom/mathml/MathMLAnchorElement.cpp
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "mozilla/dom/MathMLAnchorElement.h"

#include "mozilla/FocusModel.h"
#include "mozilla/dom/Document.h"
#include "mozilla/dom/MathMLAnchorElementBinding.h"
#include "nsContentUtils.h"
#include "nsGkAtoms.h"

namespace mozilla::dom {

NS_IMPL_CYCLE_COLLECTION_INHERITED(MathMLAnchorElement, MathMLElement, mRelList)

NS_INTERFACE_MAP_BEGIN_CYCLE_COLLECTION(MathMLAnchorElement)
  NS_INTERFACE_MAP_ENTRY(Link)
NS_INTERFACE_MAP_END_INHERITING(MathMLElement)

NS_IMPL_ADDREF_INHERITED(MathMLAnchorElement, MathMLElement)
NS_IMPL_RELEASE_INHERITED(MathMLAnchorElement, MathMLElement)

MathMLAnchorElement::MathMLAnchorElement(
    already_AddRefed<mozilla::dom::NodeInfo>&& aNodeInfo)
    : MathMLElement(std::move(aNodeInfo)) {}

JSObject* MathMLAnchorElement::WrapNode(JSContext* aCx,
                                        JS::Handle<JSObject*> aGivenProto) {
  return MathMLAnchorElement_Binding::Wrap(aCx, this, aGivenProto);
}

already_AddRefed<nsIURI> MathMLAnchorElement::GetHrefURI() const {
  const nsAttrValue* href = mAttrs.GetAttr(nsGkAtoms::href, kNameSpaceID_None);
  if (!href) {
    return nullptr;
  }
  nsAutoString hrefStr;
  href->ToString(hrefStr);
  nsCOMPtr<nsIURI> uri;
  nsContentUtils::NewURIWithDocumentCharset(getter_AddRefs(uri), hrefStr,
                                            OwnerDoc(), GetBaseURI());
  return uri.forget();
}

void MathMLAnchorElement::GetBaseTarget(nsAString& aValue) const {
  OwnerDoc()->GetBaseTarget(aValue);
}

void MathMLAnchorElement::GetLinkTargetImpl(nsAString& aTarget) {
  GetAttr(nsGkAtoms::target, aTarget);
  if (aTarget.IsEmpty()) {
    GetBaseTarget(aTarget);
  }
}

Focusable MathMLAnchorElement::IsFocusableWithoutStyle(
    IsFocusableFlags aFlags) {
  if (!IsInComposedDoc() || !OwnerDoc()->LinkHandlingEnabled() ||
      nsContentUtils::IsNodeInEditableRegion(this)) {
    return {};
  }

  int32_t tabIndex = TabIndex();
  if (!IsLink()) {
    return GetTabIndexAttrValue().isSome() ? Focusable{true, tabIndex}
                                           : Focusable{};
  }

  if (!FocusModel::IsTabFocusable(TabFocusableType::Links)) {
    tabIndex = -1;
  }
  return {true, tabIndex};
}

nsresult MathMLAnchorElement::BindToTree(BindContext& aContext,
                                         nsINode& aParent) {
  nsresult rv = MathMLElement::BindToTree(aContext, aParent);
  NS_ENSURE_SUCCESS(rv, rv);
  Link::BindToTree(aContext);
  return NS_OK;
}

void MathMLAnchorElement::UnbindFromTree(UnbindContext& aContext) {
  MathMLElement::UnbindFromTree(aContext);
  Link::UnbindFromTree();
}

void MathMLAnchorElement::AfterSetAttr(int32_t aNamespaceID, nsAtom* aName,
                                       const nsAttrValue* aValue,
                                       const nsAttrValue* aOldValue,
                                       nsIPrincipal* aSubjectPrincipal,
                                       bool aNotify) {
  if (aName == nsGkAtoms::href && aNamespaceID == kNameSpaceID_None) {
    Link::ResetLinkState(aNotify, aValue);
  }
  MathMLElement::AfterSetAttr(aNamespaceID, aName, aValue, aOldValue,
                              aSubjectPrincipal, aNotify);
}

void MathMLAnchorElement::GetEventTargetParent(EventChainPreVisitor& aVisitor) {
  Element::GetEventTargetParent(aVisitor);

  GetEventTargetParentForLinks(aVisitor);
}

nsresult MathMLAnchorElement::PostHandleEvent(EventChainPostVisitor& aVisitor) {
  return PostHandleEventForLinks(aVisitor);
}

NS_IMPL_ELEMENT_CLONE(MathMLAnchorElement)

}  // namespace mozilla::dom
```
