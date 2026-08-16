

diff --git a/Source/WTF/Scripts/Preferences/UnifiedWebPreferences.yaml b/Source/WTF/Scripts/Preferences/UnifiedWebPreferences.yaml
index 30e25f283d7d..eb416702ca22 100644
--- a/Source/WTF/Scripts/Preferences/UnifiedWebPreferences.yaml
+++ b/Source/WTF/Scripts/Preferences/UnifiedWebPreferences.yaml
@@ -5369,7 +5369,7 @@ MathFontFamily:
     WebCore:
       default: '""_str'
 
-MathMLAElementEnabled:
+MathMLAnchorElementEnabled:
   type: bool
   defaultValue:
     WebKitLegacy:
diff --git a/Source/WebCore/Headers.cmake b/Source/WebCore/Headers.cmake
index f6d8e0a092d9..71738c666f85 100644
--- a/Source/WebCore/Headers.cmake
+++ b/Source/WebCore/Headers.cmake
@@ -1538,6 +1538,7 @@ set(WebCore_PRIVATE_FRAMEWORK_HEADERS
     history/ProcessSwapDisposition.h
 
     html/Allowlist.h
+    html/AnchorElementUtils.h
     html/AttachmentAssociatedElement.h
     html/Autocapitalize.h
     html/AutocapitalizeTypes.h
diff --git a/Source/WebCore/Sources.txt b/Source/WebCore/Sources.txt
index 901b2067e172..980a96a30a2b 100644
--- a/Source/WebCore/Sources.txt
+++ b/Source/WebCore/Sources.txt
@@ -1567,6 +1567,7 @@ history/BackForwardController.cpp
 history/CachedFrame.cpp @header:RenderStyleGetters
 history/CachedPage.cpp
 history/HistoryItem.cpp
+html/AnchorElementUtils.cpp
 html/AttachmentAssociatedElement.cpp
 html/Autocapitalize.cpp
 html/Autofill.cpp
diff --git a/Source/WebCore/accessibility/AXCoreObject.h b/Source/WebCore/accessibility/AXCoreObject.h
index 74d2b4514be8..b42b11d6366e 100644
--- a/Source/WebCore/accessibility/AXCoreObject.h
+++ b/Source/WebCore/accessibility/AXCoreObject.h
@@ -1334,6 +1334,7 @@ public:
 
     // All math elements return true for isMathElement().
     virtual bool isMathElement() const = 0;
+    virtual bool isMathAnnotation() const = 0;
     virtual bool isMathFraction() const = 0;
     virtual bool isMathFenced() const = 0;
     virtual bool isMathSubscriptSuperscript() const = 0;
diff --git a/Source/WebCore/accessibility/AccessibilityMathMLElement.cpp b/Source/WebCore/accessibility/AccessibilityMathMLElement.cpp
index ff8614305874..a8577c397eda 100644
--- a/Source/WebCore/accessibility/AccessibilityMathMLElement.cpp
+++ b/Source/WebCore/accessibility/AccessibilityMathMLElement.cpp
@@ -122,12 +122,17 @@ bool AccessibilityMathMLElement::isIgnoredElementWithinMathTree() const
     if (isMathFraction() || isMathFenced() || isMathSubscriptSuperscript() || isMathRow()
         || isMathUnderOver() || isMathRoot() || isMathText() || isMathNumber()
         || isMathOperator() || isMathFenceOperator() || isMathSeparatorOperator()
-        || isMathIdentifier() || isMathTable() || isMathTableRow() || isMathTableCell() || isMathMultiscript())
+        || isMathIdentifier() || isMathTable() || isMathTableRow() || isMathTableCell() || isMathMultiscript() || isMathAnnotation())
         return false;
 
     return true;
 }
 
+bool AccessibilityMathMLElement::isMathAnnotation() const
+{
+    return elementName() == ElementName::MathML_annotation;
+}
+
 bool AccessibilityMathMLElement::isMathFraction() const
 {
     return m_renderer && m_renderer->isRenderMathMLFraction();
diff --git a/Source/WebCore/accessibility/AccessibilityMathMLElement.h b/Source/WebCore/accessibility/AccessibilityMathMLElement.h
index 1ed714805cd0..0c967ae6a6f9 100644
--- a/Source/WebCore/accessibility/AccessibilityMathMLElement.h
+++ b/Source/WebCore/accessibility/AccessibilityMathMLElement.h
@@ -55,6 +55,7 @@ private:
 
     bool isMathElement() const final { return true; }
 
+    bool isMathAnnotation() const final;
     bool isMathFraction() const final;
     bool isMathFenced() const final;
     bool isMathSubscriptSuperscript() const final;
diff --git a/Source/WebCore/accessibility/AccessibilityObject.h b/Source/WebCore/accessibility/AccessibilityObject.h
index fb11d87b25d4..b9fca2922f44 100644
--- a/Source/WebCore/accessibility/AccessibilityObject.h
+++ b/Source/WebCore/accessibility/AccessibilityObject.h
@@ -742,6 +742,7 @@ public:
     void scrollToMakeVisible(const ScrollRectToVisibleOptions&) const;
 
     // All math elements return true for isMathElement().
+    bool isMathAnnotation() const override { return false;};
     bool isMathElement() const override { return false; }
     bool isMathFraction() const override { return false; }
     bool isMathFenced() const override { return false; }
diff --git a/Source/WebCore/accessibility/atspi/AccessibilityObjectAtspi.cpp b/Source/WebCore/accessibility/atspi/AccessibilityObjectAtspi.cpp
index 431f746e0906..6376d73918c7 100644
--- a/Source/WebCore/accessibility/atspi/AccessibilityObjectAtspi.cpp
+++ b/Source/WebCore/accessibility/atspi/AccessibilityObjectAtspi.cpp
@@ -1204,6 +1204,9 @@ std::optional<Atspi::Role> AccessibilityObjectAtspi::effectiveRole() const
             return Atspi::Role::MathFraction;
         if (m_coreObject->isMathSquareRoot() || m_coreObject->isMathRoot())
             return Atspi::Role::MathRoot;
+        if (m_coreObject->isMathAnnotation()) {
+            // return Atspi::Role::Static;
+        }
         if (liveObject && (liveObject->isMathScriptObject(AccessibilityMathScriptObjectType::Subscript)
             || liveObject->isMathMultiscriptObject(AccessibilityMathMultiscriptObjectType::PreSubscript)
             || liveObject->isMathMultiscriptObject(AccessibilityMathMultiscriptObjectType::PostSubscript)))
@@ -1397,8 +1400,8 @@ AccessibilityObjectInclusion AccessibilityObject::accessibilityPlatformIncludesO
 
     // Never expose an unknown object, since AT's won't know what to
     // do with them. This is what is done on the Mac as well.
-    if (role() == AccessibilityRole::Unknown)
-        return AccessibilityObjectInclusion::IgnoreObject;
+    // if (role() == AccessibilityRole::Unknown)
+    //     return AccessibilityObjectInclusion::IgnoreObject;
 
     // The object containing the text should implement org.a11y.atspi.Text itself.
     if (role() == AccessibilityRole::StaticText)
diff --git a/Source/WebCore/html/HTMLAnchorElement.cpp b/Source/WebCore/html/HTMLAnchorElement.cpp
index e5289a52a1a6..1f2e4472f94b 100644
--- a/Source/WebCore/html/HTMLAnchorElement.cpp
+++ b/Source/WebCore/html/HTMLAnchorElement.cpp
@@ -25,6 +25,7 @@
 #include "config.h"
 #include "HTMLAnchorElement.h"
 
+#include "AnchorElementUtils.h"
 #include "Chrome.h"
 #include "ChromeClient.h"
 #include "ContainerNodeInlines.h"
@@ -241,18 +242,7 @@ void HTMLAnchorElement::attributeChanged(const QualifiedName& name, const AtomSt
     if (name == hrefAttr)
         setIsLink(!newValue.isNull() && !shouldProhibitLinks(this));
     else if (name == relAttr) {
-        // Update HTMLAnchorElement::relList() if more rel attributes values are supported.
-        static MainThreadNeverDestroyed<const AtomString> noReferrer("noreferrer"_s);
-        static MainThreadNeverDestroyed<const AtomString> noOpener("noopener"_s);
-        static MainThreadNeverDestroyed<const AtomString> opener("opener"_s);
-        m_linkRelations = { };
-        SpaceSplitString relValue(newValue, SpaceSplitString::ShouldFoldCase::Yes);
-        if (relValue.contains(noReferrer))
-            m_linkRelations.add(Relation::NoReferrer);
-        if (relValue.contains(noOpener))
-            m_linkRelations.add(Relation::NoOpener);
-        if (relValue.contains(opener))
-            m_linkRelations.add(Relation::Opener);
+        m_linkRelations = AnchorElementUtils::relationsForRelAttribute(newValue);
         if (m_relList)
             m_relList->associatedAttributeValueChanged();
     } else if (name == nameAttr)
@@ -726,12 +716,12 @@ void HTMLAnchorElement::setRootEditableElementForSelectionOnMouseDown(Element* e
 
 String HTMLAnchorElement::referrerPolicyForBindings() const
 {
-    return referrerPolicyToString(referrerPolicy());
+    return AnchorElementUtils::referrerPolicyForBindingsForHyperlinkElement(attributeWithoutSynchronization(referrerpolicyAttr));
 }
 
 ReferrerPolicy HTMLAnchorElement::referrerPolicy() const
 {
-    return parseReferrerPolicy(attributeWithoutSynchronization(referrerpolicyAttr), ReferrerPolicySource::ReferrerPolicyAttribute).value_or(ReferrerPolicy::EmptyString);
+    return AnchorElementUtils::referrerPolicyForHyperlinkElement(attributeWithoutSynchronization(referrerpolicyAttr));
 }
 
 Node::NeedsPostConnectionSteps HTMLAnchorElement::insertionSteps(InsertionType insertionType, ContainerNode& parentOfInsertedTree)
diff --git a/Source/WebCore/html/HTMLAnchorElement.h b/Source/WebCore/html/HTMLAnchorElement.h
index 2896c1267e86..94bbc92a0e6a 100644
--- a/Source/WebCore/html/HTMLAnchorElement.h
+++ b/Source/WebCore/html/HTMLAnchorElement.h
@@ -23,6 +23,7 @@
 
 #pragma once
 
+#include "AnchorElementUtils.h"
 #include <WebCore/Document.h>
 #include <WebCore/HTMLElement.h>
 #include <WebCore/HTMLNames.h>
@@ -37,14 +38,6 @@ namespace WebCore {
 class DOMTokenList;
 
 enum class ReferrerPolicy : uint8_t;
-
-// Link relation bitmask values.
-enum class Relation : uint8_t {
-    NoReferrer = 1 << 0,
-    NoOpener = 1 << 1,
-    Opener = 1 << 2,
-};
-
 class HTMLAnchorElement : public HTMLElement, public URLDecomposition {
     WTF_MAKE_TZONE_ALLOCATED(HTMLAnchorElement);
     WTF_OVERRIDE_DELETE_FOR_CHECKED_PTR(HTMLAnchorElement);
diff --git a/Source/WebCore/loader/PingLoader.cpp b/Source/WebCore/loader/PingLoader.cpp
index dffa219b2f75..b12550b9ffb2 100644
--- a/Source/WebCore/loader/PingLoader.cpp
+++ b/Source/WebCore/loader/PingLoader.cpp
@@ -265,6 +265,7 @@ void PingLoader::startPingLoad(LocalFrame& frame, ResourceRequest& request, HTTP
     }
 
     CachedResourceRequest cachedResourceRequest { ResourceRequest { request }, options };
+    cachedResourceRequest.setInitiatorType("ping"_s);
     std::ignore = protect(protect(frame.document())->cachedResourceLoader())->requestPingResource(WTF::move(cachedResourceRequest));
 }
 
diff --git a/Source/WebCore/mathml/MathMLAnchorElement.cpp b/Source/WebCore/mathml/MathMLAnchorElement.cpp
index 92582e4f586c..6c004d4598c8 100644
--- a/Source/WebCore/mathml/MathMLAnchorElement.cpp
+++ b/Source/WebCore/mathml/MathMLAnchorElement.cpp
@@ -1,16 +1,38 @@
+/*
+ * Copyright (C) 2026 Igalia S.L. All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ *
+ * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
+ * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
+ * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
+ * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
+ * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
+ * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
+ * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
+ * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
+ * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
+ * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
+ */
+
 #include "config.h"
+#include "AnchorElementUtils.h"
+
 #include "MathMLAnchorElement.h"
 
 #include "DOMTokenList.h"
-#include "Document.h"
-#include "EventHandler.h"
-#include "FrameLoader.h"
-#include "LocalFrame.h"
-#include "KeyboardEvent.h"
-#include "MathMLNames.h"
-#include "MouseEvent.h"
+#include "ElementInlines.h"
+#include "Event.h"
 #include "EventNames.h"
-#include "XLinkNames.h"
+#include "MathMLNames.h"
 #include <wtf/TZoneMallocInlines.h>
 
 namespace WebCore {
@@ -30,14 +52,14 @@ Ref<MathMLAnchorElement> MathMLAnchorElement::create(const QualifiedName& tagNam
     return adoptRef(*new MathMLAnchorElement(tagName, document));
 }
 
+URL MathMLAnchorElement::href() const
+{
+    return protect(document())->encodingParseURL(attributeWithoutSynchronization(MathMLNames::hrefAttr));
+}
+
 URL MathMLAnchorElement::hrefURL() const
 {
-    // MathML 支持 href 或 xlink:href
-    const AtomString& hrefValue = attributeWithoutSynchronization(MathMLNames::hrefAttr);
-    if (!hrefValue.isNull())
-        return protect(document())->encodingParseURL(hrefValue);
-
-    return protect(document())->encodingParseURL(attributeWithoutSynchronization(XLinkNames::hrefAttr));
+    return href();
 }
 
 AtomString MathMLAnchorElement::target() const
@@ -45,141 +67,64 @@ AtomString MathMLAnchorElement::target() const
     return attributeWithoutSynchronization(MathMLNames::targetAttr);
 }
 
-void MathMLAnchorElement::attributeChanged(const QualifiedName& name, const AtomString& oldValue, const AtomString& newValue, AttributeModificationReason attributeModificationReason)
+void MathMLAnchorElement::setFullURL(const URL& fullURL)
 {
-    MathMLElement::attributeChanged(name, oldValue, newValue, attributeModificationReason);
-
-    if (name == MathMLNames::hrefAttr || name == XLinkNames::hrefAttr) {
-        setIsLink(!newValue.isNull());
-    } else if (name == MathMLNames::relAttr) {
-        static MainThreadNeverDestroyed<const AtomString> noReferrer("noreferrer"_s);
-        static MainThreadNeverDestroyed<const AtomString> noOpener("noopener"_s);
-        static MainThreadNeverDestroyed<const AtomString> opener("opener"_s);
-        
-        m_linkRelations = { };
-        SpaceSplitString relValue(newValue, SpaceSplitString::ShouldFoldCase::Yes);
-        if (relValue.contains(noReferrer))
-            m_linkRelations.add(Relation::NoReferrer);
-        if (relValue.contains(noOpener))
-            m_linkRelations.add(Relation::NoOpener);
-        if (relValue.contains(opener))
-            m_linkRelations.add(Relation::Opener);
-            
-        if (m_relList)
-            m_relList->associatedAttributeValueChanged();
-    }
+    setAttributeWithoutSynchronization(MathMLNames::hrefAttr, AtomString { fullURL.string() });
 }
 
-static bool isEnterKeyKeydownEvent(Event& event)
-{
-    if (event.type() != eventNames().keydownEvent)
-        return false;
-    auto* keyboardEvent = dynamicDowncast<KeyboardEvent>(event);
-    return keyboardEvent && keyboardEvent->keyIdentifier() == "Enter"_s;
-}
-
-#include <wtf/text/WTFString.h>
 void MathMLAnchorElement::defaultEventHandler(Event& event)
 {
-    // 1. 打印每次进入 eventHandler 的事件类型
-    WTFLogAlways("[MathMLAnchorElement] defaultEventHandler triggered! Event type: %s, isLink(): %d",
-        event.type().string().utf8().data(), isLink());
+    if (isLink() && (event.type() == eventNames().clickEvent || event.type() == eventNames().DOMActivateEvent)) {
+        event.setDefaultHandled();
 
-    if (isLink()) {
-        if (focused() && isEnterKeyKeydownEvent(event)) {
-            WTFLogAlways("[MathMLAnchorElement] Handled as Enter keypress -> dispatching simulated click");
-            event.setDefaultHandled();
-            dispatchSimulatedClick(&event);
+        URL completedURL = hrefURL();
+        if (completedURL.isEmpty())
             return;
+
+        AtomString downloadAttr = AnchorElementUtils::downloadAttributeForHyperlinkElement(document(), completedURL, attributeWithoutSynchronization(MathMLNames::downloadAttr), hasAttributeWithoutSynchronization(MathMLNames::downloadAttr));
+
+        ReferrerPolicy policy = referrerPolicy();
+
+        if(m_linkRelations.contains(Relation::NoReferrer)) {
+            policy = ReferrerPolicy::NoReferrer;
         }
 
-        if (MouseEvent::canTriggerActivationBehavior(event)) {
-            URL completedURL = hrefURL();
-            WTFLogAlways("[MathMLAnchorElement] Computed hrefURL: '%s', isValid: %d",
-                completedURL.string().utf8().data(), completedURL.isValid());
+        AnchorElementUtils::sendPingsForHyperlinkElement(document(), attributeWithoutSynchronization(MathMLNames::pingAttr), completedURL);
 
-            if (completedURL.isValid()) {
-                Ref document = this->document();
-                auto target = this->target();
-                
-                WTFLogAlways("[MathMLAnchorElement] Target frame name: '%s'", target.string().utf8().data());
-
-                event.setDefaultHandled();
-
-                auto referrerPolicy = hasRel(Relation::NoReferrer) ? ReferrerPolicy::NoReferrer : ReferrerPolicy::EmptyString;
-                NewFrameOpenerPolicy newFrameOpenerPolicy = NewFrameOpenerPolicy::Allow;
-                if (hasRel(Relation::NoOpener) || hasRel(Relation::NoReferrer) || (!hasRel(Relation::Opener) && isBlankTargetFrameName(target) && !completedURL.protocolIsJavaScript()))
-                    newFrameOpenerPolicy = NewFrameOpenerPolicy::Suppress;
-
-                if (RefPtr frame = document->frame()) {
-                    WTFLogAlways("[MathMLAnchorElement] Calling frame->loader().changeLocation to: '%s'", completedURL.string().utf8().data());
-                    UserGestureIndicator gestureIndicator(IsProcessingUserGesture::Yes);
-                    frame->loader().changeLocation(completedURL, target, &event, referrerPolicy, document->shouldOpenExternalURLsPolicyToPropagate(), newFrameOpenerPolicy);
-                } else {
-                    WTFLogAlways("[MathMLAnchorElement] ERROR: document->frame() is NULL! Cannot navigate.");
-                }
-                return;
-            } else {
-                WTFLogAlways("[MathMLAnchorElement] URL is invalid, skipping navigation.");
-            }
-        }
-    } else {
-        WTFLogAlways("[MathMLAnchorElement] Element is NOT considered a link (isLink() == false).");
+        AnchorElementUtils::navigateHyperlink(
+            *this,
+            event,
+            completedURL,
+            effectiveTarget(),
+            m_linkRelations,
+            policy,
+            downloadAttr);
+        return;
     }
 
     MathMLElement::defaultEventHandler(event);
 }
 
-int MathMLAnchorElement::defaultTabIndex() const
+void MathMLAnchorElement::attributeChanged(const QualifiedName& name, const AtomString& oldValue, const AtomString& newValue, AttributeModificationReason attributeModificationReason)
 {
-    return 0;
+    MathMLElement::attributeChanged(name, oldValue, newValue, attributeModificationReason);
+
+    if (name == MathMLNames::relAttr) {
+        m_linkRelations = AnchorElementUtils::relationsForRelAttribute(newValue);
+        if (m_relList)
+            m_relList->associatedAttributeValueChanged();
+    }
 }
 
-bool MathMLAnchorElement::supportsFocus() const
+// Falls back to using <base> element's target if the anchor does not have one.
+AtomString MathMLAnchorElement::effectiveTarget() const
 {
-    if (hasEditableStyle())
-        return MathMLElement::supportsFocus();
-    return isLink() || MathMLElement::supportsFocus();
+    auto effectiveTarget = target();
+    if (effectiveTarget.isEmpty())
+        effectiveTarget = document().baseTarget();
+    return makeTargetBlankIfHasDanglingMarkup(effectiveTarget);
 }
 
-bool MathMLAnchorElement::isMouseFocusable() const
-{
-    if (isLink())
-        return Element::supportsFocus();
-    return MathMLElement::isMouseFocusable();
-}
-
-bool MathMLAnchorElement::isKeyboardFocusable(const FocusEventData& focusEventData) const
-{
-    if (isFocusable() && Element::supportsFocus())
-        return MathMLElement::isKeyboardFocusable(focusEventData);
-
-    RefPtr frame = document().frame();
-    if (!frame)
-        return false;
-
-    if (isLink() && !frame->eventHandler().tabsToLinks(focusEventData))
-        return false;
-
-    return MathMLElement::isKeyboardFocusable(focusEventData);
-}
-
-bool MathMLAnchorElement::isURLAttribute(const Attribute& attribute) const
-{
-    return attribute.name() == MathMLNames::hrefAttr || attribute.name() == XLinkNames::hrefAttr || MathMLElement::isURLAttribute(attribute);
-}
-
-bool MathMLAnchorElement::canStartSelection() const
-{
-    if (!isLink())
-        return MathMLElement::canStartSelection();
-    return hasEditableStyle();
-}
-
-bool MathMLAnchorElement::willRespondToMouseClickEventsWithEditability(Editability editability) const
-{
-    return isLink() || MathMLElement::willRespondToMouseClickEventsWithEditability(editability);
-}
 
 DOMTokenList& MathMLAnchorElement::relList()
 {
@@ -196,4 +141,14 @@ bool MathMLAnchorElement::hasRel(Relation relation) const
     return m_linkRelations.contains(relation);
 }
 
-} // namespace WebCore
\ No newline at end of file
+String MathMLAnchorElement::referrerPolicyForBindings() const
+{
+    return AnchorElementUtils::referrerPolicyForBindingsForHyperlinkElement(attributeWithoutSynchronization(MathMLNames::referrerpolicyAttr));
+}
+
+ReferrerPolicy MathMLAnchorElement::referrerPolicy() const
+{
+    return AnchorElementUtils::referrerPolicyForHyperlinkElement(attributeWithoutSynchronization(MathMLNames::referrerpolicyAttr));
+}
+
+} // namespace WebCore
diff --git a/Source/WebCore/mathml/MathMLAnchorElement.h b/Source/WebCore/mathml/MathMLAnchorElement.h
index 591d3b67e093..74b251fa8409 100644
--- a/Source/WebCore/mathml/MathMLAnchorElement.h
+++ b/Source/WebCore/mathml/MathMLAnchorElement.h
@@ -26,7 +26,7 @@
 #pragma once
 
 #include "MathMLElement.h"
-#include "ReferrerPolicy.h"
+#include "URLDecomposition.h"
 #include <wtf/OptionSet.h>
 #include <wtf/TZoneMalloc.h>
 
@@ -35,41 +35,38 @@ namespace WebCore {
 class DOMTokenList;
 
 enum class ReferrerPolicy : uint8_t;
+enum class Relation : uint8_t;
 
-class MathMLAnchorElement final : public MathMLElement {
+class MathMLAnchorElement final : public MathMLElement, public URLDecomposition {
     WTF_MAKE_TZONE_ALLOCATED(MathMLAnchorElement);
     WTF_OVERRIDE_DELETE_FOR_CHECKED_PTR(MathMLAnchorElement);
 
 public:
-    // Link relation bitmask values.
-    enum class Relation : uint8_t {
-        NoReferrer = 1 << 0,
-        NoOpener = 1 << 1,
-        Opener = 1 << 2,
-    };
-
     static Ref<MathMLAnchorElement> create(const QualifiedName&, Document&);
     virtual ~MathMLAnchorElement();
 
+    WEBCORE_EXPORT URL href() const;
+
     URL hrefURL() const;
     AtomString target() const final;
 
+    URL fullURL() const final { return href(); }
+    void setFullURL(const URL&) final;
+
+    void defaultEventHandler(Event& event);
+
     bool hasRel(Relation relation) const;
     DOMTokenList& relList();
 
+    String referrerPolicyForBindings() const;
+    ReferrerPolicy referrerPolicy() const;
+
 private:
     MathMLAnchorElement(const QualifiedName&, Document&);
 
+    AtomString effectiveTarget() const;
+
     void attributeChanged(const QualifiedName&, const AtomString& oldValue, const AtomString& newValue, AttributeModificationReason) final;
-    
-    void defaultEventHandler(Event&) final;
-    bool supportsFocus() const final;
-    bool isMouseFocusable() const final;
-    bool isKeyboardFocusable(const FocusEventData&) const final;
-    bool isURLAttribute(const Attribute&) const final;
-    bool canStartSelection() const final;
-    int defaultTabIndex() const final;
-    bool willRespondToMouseClickEventsWithEditability(Editability) const final;
 
     OptionSet<Relation> m_linkRelations;
     const std::unique_ptr<DOMTokenList> m_relList;
diff --git a/Source/WebCore/mathml/MathMLAnchorElement.idl b/Source/WebCore/mathml/MathMLAnchorElement.idl
index 644b8a769fbd..daa5b64c1b29 100644
--- a/Source/WebCore/mathml/MathMLAnchorElement.idl
+++ b/Source/WebCore/mathml/MathMLAnchorElement.idl
@@ -24,11 +24,17 @@
  */
 
 [
-    EnabledBySetting=MathMLAElementEnabled,
+    EnabledBySetting=MathMLAnchorElementEnabled,
     Exposed=Window,
 ] interface MathMLAnchorElement : MathMLElement {
-    [Reflect] attribute DOMString href;
-    [Reflect] attribute DOMString target;
-    [Reflect] attribute DOMString rel;
+    [CEReactions=NotNeeded, ReflectURL] stringifier attribute USVString href;
+    [CEReactions=NotNeeded, Reflect] attribute DOMString target;
+
+    [CEReactions=NotNeeded, Reflect] attribute DOMString download;
+    [CEReactions=NotNeeded, Reflect] attribute USVString ping;
+    [CEReactions=NotNeeded, Reflect] attribute DOMString rel;
     [SameObject, PutForwards=value] readonly attribute DOMTokenList relList;
-};
\ No newline at end of file
+    [CEReactions=NotNeeded, ImplementedAs=referrerPolicyForBindings, ReflectSetter] attribute [AtomString] DOMString referrerPolicy;
+};
+
+MathMLAnchorElement includes HyperlinkElementUtils;
\ No newline at end of file
diff --git a/Source/WebCore/mathml/mathattrs.in b/Source/WebCore/mathml/mathattrs.in
index f9335cb6d096..6f3b4216516d 100644
--- a/Source/WebCore/mathml/mathattrs.in
+++ b/Source/WebCore/mathml/mathattrs.in
@@ -11,6 +11,7 @@ close
 color
 columnspan
 definitionURL
+download
 denomalign
 depth
 dir
@@ -24,6 +25,7 @@ fontstyle
 fontweight
 form
 height
+hreflang
 href
 largeop
 linethickness
@@ -38,6 +40,8 @@ movablelimits
 notation
 numalign
 open
+ping
+referrerpolicy
 rel
 rowspan
 rspace
@@ -49,6 +53,7 @@ src
 stretchy
 symmetric
 subscriptshift
+type
 superscriptshift
 target
 voffset
diff --git a/Source/WebCore/page/Performance.cpp b/Source/WebCore/page/Performance.cpp
index a47043aeb28c..4e790e768a2f 100644
--- a/Source/WebCore/page/Performance.cpp
+++ b/Source/WebCore/page/Performance.cpp
@@ -432,7 +432,7 @@ void Performance::navigationFinished(MonotonicTime loadEventEnd)
 void Performance::addResourceTiming(ResourceTiming&& resourceTiming)
 {
     ASSERT(scriptExecutionContext());
-
+    WTFReportBacktrace();
     auto entry = PerformanceResourceTiming::create(m_timeOrigin, WTF::move(resourceTiming));
 
     if (m_waitingForBackupBufferToBeProcessed) {
diff --git a/Source/WebCore/page/PerformanceResourceTiming.cpp b/Source/WebCore/page/PerformanceResourceTiming.cpp
index 7476ec9af5b7..3e83077b9cbf 100644
--- a/Source/WebCore/page/PerformanceResourceTiming.cpp
+++ b/Source/WebCore/page/PerformanceResourceTiming.cpp
@@ -100,6 +100,9 @@ PerformanceResourceTiming::PerformanceResourceTiming(MonotonicTime timeOrigin, R
     , m_resourceTiming(WTF::move(resourceTiming))
     , m_serverTiming(m_resourceTiming.populateServerTiming())
 {
+    WTFLogAlways("===> PerformanceResourceTiming created for URL: %s, initiatorType: %s", 
+        m_resourceTiming.url().string().utf8().data(), 
+        m_resourceTiming.initiatorType().utf8().data());
 }
 
 PerformanceResourceTiming::~PerformanceResourceTiming() = default;



 0:24.45 SUITE_END

web-platform-test
~~~~~~~~~~~~~~~~~
Ran 422 checks (336 subtests, 86 tests)
Expected results: 419
Unexpected results: 3
  subtest: 3 (3 fail)

Error Summary
-------------
/referrer-policy/gen/srcdoc.meta/default/mathml-a-tag.http.html
  FAIL Referrer Policy: Expects origin for mathml-a-tag to cross-http origin and no-redirect redirection from http context. - assert_in_array: document.referrer value "http://web-platform.test:8000/referrer-policy/gen/srcdoc.meta/default/mathml-a-tag.http.html" not in array ["http://web-platform.test:8000/", undefined]
checkResult@http://web-platform.test:8000/referrer-policy/generic/test-case.sub.js:83:18
TestCase/runTest/</<@http://web-platform.test:8000/referrer-policy/generic/test-case.sub.js:116:36
  FAIL Referrer Policy: Expects origin for mathml-a-tag to cross-https origin and no-redirect redirection from http context. - assert_in_array: document.referrer value "http://web-platform.test:8000/referrer-policy/gen/srcdoc.meta/default/mathml-a-tag.http.html" not in array ["http://web-platform.test:8000/", undefined]
checkResult@http://web-platform.test:8000/referrer-policy/generic/test-case.sub.js:83:18
TestCase/runTest/</<@http://web-platform.test:8000/referrer-policy/generic/test-case.sub.js:116:36
  FAIL Referrer Policy: Expects origin for mathml-a-tag to same-https origin and no-redirect redirection from http context. - assert_in_array: document.referrer value "http://web-platform.test:8000/referrer-policy/gen/srcdoc.meta/default/mathml-a-tag.http.html" not in array ["http://web-platform.test:8000/", undefined]
checkResult@http://web-platform.test:8000/referrer-policy/generic/test-case.sub.js:83:18
TestCase/runTest/</<@http://web-platform.test:8000/referrer-policy/generic/test-case.sub.js:116:36
 0:24.45 INFO Got 1 unexpected results, with 0 unexpected passes
 0:24.45 wptserve INFO Stopped http server on 127.0.0.1:8000
 0:24.45 wptserve INFO Stopped http server on 127.0.0.1:8001
 0:24.45 wptserve INFO Stopped http server on 127.0.0.1:8002
 0:24.45 wptserve INFO Stopped http server on 127.0.0.1:8003
 0:24.45 wptserve INFO Stopped http server on 127.0.0.1:8443
 0:24.45 wptserve INFO Stopped http server on 127.0.0.1:8445
 0:24.45 wptserve INFO Stopped http server on 127.0.0.1:8444
 0:24.45 wptserve INFO Stopped http server on 127.0.0.1:8446
 0:24.45 wptserve INFO Stopped http server on 127.0.0.1:9000
 0:24.45 wptserve INFO Stopped WebTransport over HTTP/3 server on 127.0.0.1:11000
 0:24.70 wptserve INFO Close on: (<AddressFamily.AF_INET: 2>, <SocketKind.SOCK_STREAM: 1>, 6, '', ('127.0.0.1', 8888))
 0:24.70 wptserve INFO Close on: (<AddressFamily.AF_INET: 2>, <SocketKind.SOCK_STREAM: 1>, 6, '', ('127.0.0.1', 8889))
 0:24.75 INFO Closing logging queue
 0:24.75 INFO queue closed


115 tests ran as expected, 15 didn't:
    external/wpt/referrer-policy/gen/iframe-inherit.http-rp/no-referrer/mathml-a-tag.http.html
    external/wpt/referrer-policy/gen/iframe-inherit.http-rp/origin/mathml-a-tag.http.html
    external/wpt/referrer-policy/gen/iframe-inherit.http-rp/same-origin/mathml-a-tag.http.html
    external/wpt/referrer-policy/gen/iframe-inherit.http-rp/strict-origin/mathml-a-tag.http.html
    external/wpt/referrer-policy/gen/iframe-inherit.meta/never/mathml-a-tag.http.html
    external/wpt/referrer-policy/gen/iframe-inherit.meta/no-referrer/mathml-a-tag.http.html
    external/wpt/referrer-policy/gen/iframe-inherit.meta/origin/mathml-a-tag.http.html
    external/wpt/referrer-policy/gen/iframe-inherit.meta/same-origin/mathml-a-tag.http.html
    external/wpt/referrer-policy/gen/iframe-inherit.meta/strict-origin/mathml-a-tag.http.html
    external/wpt/referrer-policy/gen/req.attr/no-referrer/mathml-a-tag.http.html
    external/wpt/referrer-policy/gen/req.attr/origin-when-cross-origin/mathml-a-tag.http.html
    external/wpt/referrer-policy/gen/req.attr/origin/mathml-a-tag.http.html
    external/wpt/referrer-policy/gen/req.attr/same-origin/mathml-a-tag.http.html
    external/wpt/referrer-policy/gen/req.attr/strict-origin-when-cross-origin/mathml-a-tag.http.html
    external/wpt/referrer-policy/gen/req.attr/strict-origin/mathml-a-tag.http.html


```
diff --git a/core-aam/aamtests/support/atspi_wrapper.py b/core-aam/aamtests/support/atspi_wrapper.py
index 958b1ea163..512c4b62b3 100644
--- a/core-aam/aamtests/support/atspi_wrapper.py
+++ b/core-aam/aamtests/support/atspi_wrapper.py
@@ -28,7 +28,6 @@ class AtspiWrapper(ApiWrapper[Atspi.Accessible]):
             self.document = self._poll_for(
                 self._find_fully_loaded_tab, f"Timeout looking for url: {self.test_url}"
             )
-
         test_node = self._find_node_by_id(self.document, dom_id);
         if not test_node:
             raise Exception(f"Did not find node with id '{dom_id}' in accessibility API ATSPI.")
@@ -120,30 +119,21 @@ class AtspiWrapper(ApiWrapper[Atspi.Accessible]):
         return None
 
     def _find_fully_loaded_tab(self) -> Optional[Atspi.Accessible]:
-        """Find the tab with the test url. Only returns the tab when the tab is ready.
+            """Find the document web node in MiniBrowser."""
+            stack = [self.root]
+            while stack:
+                node = stack.pop()
+                if not node:
+                    continue
 
-        :param url: The url of the test.
-        :return: Atspi.Accessible representing test document or None.
-        """
-        stack = [self.root]
-        while stack:
-            node = stack.pop()
-            if Atspi.Accessible.get_role_name(node) == "frame":
-                relationset = Atspi.Accessible.get_relation_set(node)
-                for relation in relationset:
-                    if relation.get_relation_type() == Atspi.RelationType.EMBEDS:
-                        tab = relation.get_target(0)
-                        if self._is_ready(tab, self.test_url):
-                            return tab
-                        else:
-                            return None
-                continue
+                if Atspi.Accessible.get_role_name(node) == "document web":
+                    if self._is_ready(node, self.test_url):
+                        return node
 
-            for i in range(Atspi.Accessible.get_child_count(node)):
-                child = Atspi.Accessible.get_child_at_index(node, i)
-                stack.append(child)
+                for i in range(Atspi.Accessible.get_child_count(node)):
+                    stack.append(Atspi.Accessible.get_child_at_index(node, i))
 
-        return None
+            return None
 
     def _is_ready(self, tab: Atspi.Accessible, url: str) -> bool:
         """Test whether tab is fully loaded.
diff --git a/core-aam/aamtests/support/fixtures_a11y_api.py b/core-aam/aamtests/support/fixtures_a11y_api.py
index 4cf85804e8..b753af5aaa 100644
--- a/core-aam/aamtests/support/fixtures_a11y_api.py
+++ b/core-aam/aamtests/support/fixtures_a11y_api.py
@@ -12,6 +12,8 @@ def pid_from(capabilities):
         return capabilities["safari:processID"], capabilities["browserName"]
     if capabilities["browserName"] == "MicrosoftEdge":
         return capabilities["goog:processID"], "edge"
+    if capabilities["browserName"] == "MiniBrowser":
+        return capabilities["webkit:processID"], "webkit"
     return 0, capabilities["browserName"]
 
 
diff --git a/tools/wptrunner/wptrunner/browsers/webkit.py b/tools/wptrunner/wptrunner/browsers/webkit.py
index 66c675188f..7b5a7e7af5 100644
--- a/tools/wptrunner/wptrunner/browsers/webkit.py
+++ b/tools/wptrunner/wptrunner/browsers/webkit.py
@@ -41,12 +41,13 @@ def browser_kwargs(logger, test_type, run_info_data, config, **kwargs):
 def capabilities_for_port(server_config, **kwargs):
     port_name = kwargs["webkit_port"]
     if port_name in ["gtk", "wpe"]:
-        port_key_map = {"gtk": "webkitgtk"}
+        port_key_map = {"gtk": "webkit"}
         browser_options_port = port_key_map.get(port_name, port_name)
         browser_options_key = "%s:browserOptions" % browser_options_port
 
         return {
             "browserName": "MiniBrowser",
+            "acceptInsecureCerts": True,
             "browserVersion": "2.20",
             "platformName": "ANY",
             browser_options_key: {

```

```
void GetHref(nsAString& aHref, ErrorResult& aRv) const {
  // 1. 获取 raw href 属性值
  const nsAttrValue* attr = mAttrs.GetAttr(nsGkAtoms::href);
  if (!attr) {
    // 属性不存在，清空返回值并直接返回
    aHref.Truncate();
    return;
  }

  // 2. 获取文档的基准 URI (Base URI)
  nsCOMPtr<nsIURI> baseURI = GetBaseURI();

  // 3. 尝试将 href 解析为绝对 URI (nsIURI)
  nsCOMPtr<nsIURI> uri;
  nsresult rv = nsContentUtils::NewURIWithDocumentCharset(
      getter_AddRefs(uri), nsAttrValueOrString(attr).String(), OwnerDoc(), baseURI);

  // 4. 判断 URI 是否解析成功
  if (NS_FAILED(rv) || !uri) {
    // 失败/无法解析（例如 href 是 "javascript:..." 或非法 URL）：
    // 回退处理：直接返回未经解析的原始属性字符串
    attr->ToString(aHref);
    return;
  }

  // 5. 成功解析：获取规范化的绝对 URI 字符串 (UTF-8)
  nsAutoCString spec;
  rv = uri->GetSpec(spec);
  if (NS_FAILED(rv)) {
    // 极罕见的获取失败回退
    attr->ToString(aHref);
    return;
  }

  // 6. 将 UTF-8 的 URI spec 转换为 DOM 要求的 UTF-16 nsAString
  CopyUTF8toUTF16(spec, aHref);
}
```


CSP diff

```diff
diff --git a/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-attr-header-match.html b/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-attr-header-match.html
new file mode 100644
index 0000000000000..abed6b8055928
--- /dev/null
+++ b/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-attr-header-match.html
@@ -0,0 +1,39 @@
+<!doctype html>
+<meta charset="utf-8">
+<title>MathML CSP: HTTP Header Hash MATCH Scenario</title>
+<link rel="help" href="https://w3c.github.io/webappsec-csp/#directive-style-src-attr">
+
+<script src="/resources/testharness.js"></script>
+<script src="/resources/testharnessreport.js"></script>
+<script src="/mathml/support/mathml-fragments.js"></script>
+<script src="/mathml/support/csp-test-helper.js"></script>
+
+<body>
+<script>
+  for (const tag in MathMLFragments) {
+    test((t) => {
+      // 1. Create a container and append the MathML element to the document.
+      const container = document.createElement("div");
+      container.innerHTML = `<math>${MathMLFragments[tag]}</math>`;
+      document.body.appendChild(container);
+
+      // 2. Register cleanup to remove the element after the test finishes.
+      t.add_cleanup(() => container.remove());
+
+      const mathEl = FragmentHelper.element(container.firstElementChild);
+
+      // 3. Inject inline style text matching the hash configured in the .headers file.
+      mathEl.setAttribute("style", TEST_CSS_TEXT);
+
+      // 4. Verify that the inline style is successfully applied due to the CSP hash match.
+      const computedColor = window.getComputedStyle(mathEl).color;
+      assert_equals(
+        computedColor, 
+        APPLIED_COLOR_RGB, 
+        `Style should be applied to <${tag}> when CSP header hash matches inline style attribute. ` +
+        `Expected: "${APPLIED_COLOR_RGB}", Actual computed color: "${computedColor}"`
+      );
+    }, `HTTP Header Hash MATCH: <${tag}>`);
+  }
+</script>
+</body>
\ No newline at end of file
diff --git a/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-attr-header-match.html.headers b/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-attr-header-match.html.headers
new file mode 100644
index 0000000000000..00a5114227861
--- /dev/null
+++ b/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-attr-header-match.html.headers
@@ -0,0 +1 @@
+Content-Security-Policy: style-src-attr 'unsafe-hashes' 'sha256-cgrWcJeXGgvsbzqeXr9ARPkciN38f5Rd6u0ahueqhkU=';
\ No newline at end of file
diff --git a/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-attr-header-mismatch.html b/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-attr-header-mismatch.html
new file mode 100644
index 0000000000000..4ad3be29dbb87
--- /dev/null
+++ b/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-attr-header-mismatch.html
@@ -0,0 +1,39 @@
+<!doctype html>
+<meta charset="utf-8">
+<title>MathML CSP: HTTP Header Hash MISMATCH Scenario</title>
+<link rel="help" href="https://w3c.github.io/webappsec-csp/#directive-style-src-attr">
+
+<script src="/resources/testharness.js"></script>
+<script src="/resources/testharnessreport.js"></script>
+<script src="/mathml/support/mathml-fragments.js"></script>
+<script src="/mathml/support/csp-test-helper.js"></script>
+
+<body>
+<script>
+  for (const tag in MathMLFragments) {
+    test((t) => {
+      // 1. Create a container and append the MathML element to the document.
+      const container = document.createElement("div");
+      container.innerHTML = `<math>${MathMLFragments[tag]}</math>`;
+      document.body.appendChild(container);
+
+      // 2. Register cleanup to remove the node after the test completes.
+      t.add_cleanup(() => container.remove());
+
+      const mathEl = FragmentHelper.element(container.firstElementChild);
+
+      // 3. Inject inline style text that does NOT match the hash specified in the .headers file.
+      mathEl.setAttribute("style", TEST_CSS_TEXT);
+
+      // 4. Verify that the inline style is blocked due to the CSP hash mismatch.
+      const computedColor = window.getComputedStyle(mathEl).color;
+      assert_not_equals(
+        computedColor, 
+        APPLIED_COLOR_RGB, 
+        `Style should be blocked on <${tag}> when CSP header hash mismatches the inline style attribute. ` +
+        `Expected computed color to NOT be "${APPLIED_COLOR_RGB}", but got "${computedColor}".`
+      );
+    }, `HTTP Header Hash MISMATCH: <${tag}>`);
+  }
+</script>
+</body>
\ No newline at end of file
diff --git a/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-attr-header-mismatch.html.headers b/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-attr-header-mismatch.html.headers
new file mode 100644
index 0000000000000..a9b066c1ae0b6
--- /dev/null
+++ b/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-attr-header-mismatch.html.headers
@@ -0,0 +1 @@
+Content-Security-Policy: style-src-attr 'unsafe-hashes' 'sha256-R3M4103q4fU+fH2G207wA0lD4Z14aV25x653eP0v018=';
\ No newline at end of file
diff --git a/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-attr-meta.html b/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-attr-meta.html
new file mode 100644
index 0000000000000..47b80d3b356ba
--- /dev/null
+++ b/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-attr-meta.html
@@ -0,0 +1,62 @@
+<!doctype html>
+<meta charset="utf-8">
+<title>MathML CSP: style-src-attr Meta Matrix</title>
+<link rel="help" href="https://w3c.github.io/webappsec-csp/#directive-style-src-attr">
+
+<script src="/resources/testharness.js"></script>
+<script src="/resources/testharnessreport.js"></script>
+<script src="/mathml/support/mathml-fragments.js"></script>
+<script src="/mathml/support/csp-test-helper.js"></script>
+
+<body>
+<script>
+  /**
+   * Helper runner to generate individual WPT tests for every MathML fragment tag.
+   */
+  function generateTestSuite(descriptionPrefix, options) {
+    for (const tag in MathMLFragments) {
+      promise_test(async (t) => {
+        await runMathMLCSPTestForTag(t, { tag, ...options });
+      }, `${descriptionPrefix}: <${tag}>`);
+    }
+  }
+
+  // =========================================================================
+  // Dimension 1: CSP Meta Absent -> Inline style attribute allowed
+  // =========================================================================
+  generateTestSuite("Meta Absent", {
+    targetType: "attr",
+    metaPolicyBuilder: null,
+    shouldApply: true
+  });
+
+  // =========================================================================
+  // Dimension 2: CSP Meta 'none' -> Inline style attribute blocked
+  // =========================================================================
+  generateTestSuite("Meta Present ('none')", {
+    targetType: "attr",
+    metaPolicyBuilder: () => "style-src-attr 'none';",
+    shouldApply: false
+  });
+
+  // =========================================================================
+  // Dimension 3: CSP Meta Hash MATCH -> Inline style attribute allowed
+  // =========================================================================
+  generateTestSuite("Meta Present (Hash MATCH)", {
+    targetType: "attr",
+    metaPolicyBuilder: (hash) => `style-src-attr 'unsafe-hashes' '${hash}';`,
+    hashShouldMatch: true,
+    shouldApply: true
+  });
+
+  // =========================================================================
+  // Dimension 4: CSP Meta Hash MISMATCH -> Inline style attribute blocked
+  // =========================================================================
+  generateTestSuite("Meta Present (Hash MISMATCH)", {
+    targetType: "attr",
+    metaPolicyBuilder: (hash) => `style-src-attr 'unsafe-hashes' '${hash}';`,
+    hashShouldMatch: false,
+    shouldApply: false
+  });
+</script>
+</body>
\ No newline at end of file
diff --git a/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-elem-meta.html b/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-elem-meta.html
new file mode 100644
index 0000000000000..c883ca59a5c13
--- /dev/null
+++ b/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-elem-meta.html
@@ -0,0 +1,63 @@
+<!doctype html>
+<meta charset="utf-8">
+<title>MathML CSP: style-src-elem Meta Existence & Hash Match/Mismatch Matrix</title>
+<link rel="help" href="https://w3c.github.io/webappsec-csp/#directive-style-src-elem">
+
+<script src="/resources/testharness.js"></script>
+<script src="/resources/testharnessreport.js"></script>
+<script src="/mathml/support/mathml-fragments.js"></script>
+<script src="/mathml/support/csp-test-helper.js"></script>
+
+<body>
+<script>
+  /**
+   * Helper runner to generate individual WPT subtests for every MathML fragment tag.
+   */
+  function generateTestSuite(descriptionPrefix, options) {
+    for (const tag in MathMLFragments) {
+      promise_test(async (t) => {
+        await runMathMLCSPTestForTag(t, { tag, ...options });
+      }, `${descriptionPrefix}: <${tag}>`);
+    }
+  }
+
+  // =========================================================================
+  // Dimension 1: CSP Meta Absent -> <style> element allowed
+  // =========================================================================
+  generateTestSuite("Meta Absent", {
+    targetType: "elem",
+    metaPolicyBuilder: null,
+    shouldApply: true
+  });
+
+  // =========================================================================
+  // Dimension 2: CSP Meta 'none' -> <style> element blocked
+  // =========================================================================
+  generateTestSuite("Meta Present ('none')", {
+    targetType: "elem",
+    metaPolicyBuilder: () => "style-src-elem 'none';",
+    shouldApply: false
+  });
+
+  // =========================================================================
+  // Dimension 3: CSP Meta Hash MATCH -> <style> element allowed
+  // Note: <style> element hashes do not require 'unsafe-hashes'.
+  // =========================================================================
+  generateTestSuite("Meta Present (Hash MATCH)", {
+    targetType: "elem",
+    metaPolicyBuilder: (hash) => `style-src-elem '${hash}';`,
+    hashShouldMatch: true,
+    shouldApply: true
+  });
+
+  // =========================================================================
+  // Dimension 4: CSP Meta Hash MISMATCH -> <style> element blocked
+  // =========================================================================
+  generateTestSuite("Meta Present (Hash MISMATCH)", {
+    targetType: "elem",
+    metaPolicyBuilder: (hash) => `style-src-elem '${hash}';`,
+    hashShouldMatch: false,
+    shouldApply: false
+  });
+</script>
+</body>
\ No newline at end of file
diff --git a/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-fallback-meta.html b/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-fallback-meta.html
new file mode 100644
index 0000000000000..8557ab55b8af1
--- /dev/null
+++ b/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-fallback-meta.html
@@ -0,0 +1,71 @@
+<!doctype html>
+<meta charset="utf-8">
+<title>MathML CSP: style-src Directive Fallback & Override Matrix</title>
+<link rel="help" href="https://w3c.github.io/webappsec-csp/#effective-directive-for-inline-check">
+
+<script src="/resources/testharness.js"></script>
+<script src="/resources/testharnessreport.js"></script>
+<script src="/mathml/support/mathml-fragments.js"></script>
+<script src="/mathml/support/csp-test-helper.js"></script>
+
+<body>
+<script>
+  /**
+   * Helper runner to generate individual WPT subtests for every MathML fragment tag.
+   */
+  function generateTestSuite(descriptionPrefix, options) {
+    for (const tag in MathMLFragments) {
+      promise_test(async (t) => {
+        await runMathMLCSPTestForTag(t, { tag, ...options });
+      }, `${descriptionPrefix}: <${tag}>`);
+    }
+  }
+
+  // =========================================================================
+  // Scenario 1: Fallback -> 'style-src "none"' falls back to block style attributes
+  // =========================================================================
+  generateTestSuite("Fallback (style-src 'none' -> attr)", {
+    targetType: "attr",
+    metaPolicyBuilder: () => "style-src 'none';",
+    shouldApply: false
+  });
+
+  // =========================================================================
+  // Scenario 2: Fallback -> 'style-src "none"' falls back to block <style> elements
+  // =========================================================================
+  generateTestSuite("Fallback (style-src 'none' -> elem)", {
+    targetType: "elem",
+    metaPolicyBuilder: () => "style-src 'none';",
+    shouldApply: false
+  });
+
+  // =========================================================================
+  // Scenario 3: Fallback + Hash MATCH -> 'style-src' hash allows matching <style> elements
+  // =========================================================================
+  generateTestSuite("Fallback (Hash MATCH: style-src '${hash}')", {
+    targetType: "elem",
+    metaPolicyBuilder: (hash) => `style-src '${hash}';`,
+    hashShouldMatch: true,
+    shouldApply: true
+  });
+
+  // =========================================================================
+  // Scenario 4: Override -> Specific 'style-src-attr' overrides 'style-src' for attributes
+  // =========================================================================
+  generateTestSuite("Override (style-src-attr overrides style-src)", {
+    targetType: "attr",
+    metaPolicyBuilder: () => "style-src 'none'; style-src-attr 'unsafe-inline';",
+    shouldApply: true
+  });
+
+  // =========================================================================
+  // Scenario 5: Override -> Specific 'style-src-elem' overrides 'style-src' for <style> elements
+  // =========================================================================
+  generateTestSuite("Override (style-src-elem overrides style-src)", {
+    targetType: "elem",
+    metaPolicyBuilder: (hash) => `style-src 'none'; style-src-elem '${hash}';`,
+    hashShouldMatch: true,
+    shouldApply: true
+  });
+</script>
+</body>
\ No newline at end of file
diff --git a/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-nonce-meta.html b/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-nonce-meta.html
new file mode 100644
index 0000000000000..62e78eeafa8c2
--- /dev/null
+++ b/third_party/blink/web_tests/external/wpt/mathml/relations/html5-tree/style-src-nonce-meta.html
@@ -0,0 +1,64 @@
+<!doctype html>
+<meta charset="utf-8">
+<title>MathML CSP: style-src Nonce Matching Matrix</title>
+<link rel="help" href="https://w3c.github.io/webappsec-csp/#directive-style-src">
+
+<script src="/resources/testharness.js"></script>
+<script src="/resources/testharnessreport.js"></script>
+<script src="/mathml/support/mathml-fragments.js"></script>
+<script src="/mathml/support/csp-test-helper.js"></script>
+
+<body>
+<script>
+  const VALID_NONCE = "rAnd0m123456";
+  const INVALID_NONCE = "wrongNonce999";
+
+  /**
+   * Helper runner to generate individual WPT subtests for <style nonce="..."> elements on MathML tags.
+   */
+  function generateNonceTestSuite(descriptionPrefix, { nonceInPolicy, nonceOnStyleElement, shouldApply }) {
+    for (const tag in MathMLFragments) {
+      promise_test(async (t) => {
+        await runMathMLCSPTestForTag(t, {
+          tag,
+          targetType: "elem",
+          metaPolicyBuilder: () => `style-src 'nonce-${nonceInPolicy}';`,
+          elementModifier: (styleEl) => {
+            if (nonceOnStyleElement) {
+              styleEl.setAttribute("nonce", nonceOnStyleElement);
+            }
+          },
+          shouldApply
+        });
+      }, `${descriptionPrefix}: <${tag}>`);
+    }
+  }
+
+  // =========================================================================
+  // Dimension 1: Nonce MATCH -> <style nonce="..."> allowed on MathML elements
+  // =========================================================================
+  generateNonceTestSuite("Nonce MATCH", {
+    nonceInPolicy: VALID_NONCE,
+    nonceOnStyleElement: VALID_NONCE,
+    shouldApply: true
+  });
+
+  // =========================================================================
+  // Dimension 2: Nonce MISMATCH -> <style nonce="..."> blocked on MathML elements
+  // =========================================================================
+  generateNonceTestSuite("Nonce MISMATCH", {
+    nonceInPolicy: VALID_NONCE,
+    nonceOnStyleElement: INVALID_NONCE,
+    shouldApply: false
+  });
+
+  // =========================================================================
+  // Dimension 3: Nonce MISSING -> <style> without nonce blocked on MathML elements
+  // =========================================================================
+  generateNonceTestSuite("Nonce MISSING", {
+    nonceInPolicy: VALID_NONCE,
+    nonceOnStyleElement: null,
+    shouldApply: false
+  });
+</script>
+</body>
\ No newline at end of file
diff --git a/third_party/blink/web_tests/external/wpt/mathml/support/csp-test-helper.js b/third_party/blink/web_tests/external/wpt/mathml/support/csp-test-helper.js
new file mode 100644
index 0000000000000..be6af7e01c9ab
--- /dev/null
+++ b/third_party/blink/web_tests/external/wpt/mathml/support/csp-test-helper.js
@@ -0,0 +1,100 @@
+/**
+ * MathML CSP Unified Test Helper
+ */
+
+const TEST_CSS_TEXT = "color: rgb(0, 128, 0)"; // green
+const APPLIED_COLOR_RGB = "rgb(0, 128, 0)";
+
+/**
+ * Native Web Crypto SHA-256 Hash Computation
+ * @param {string} text - The CSS string to hash.
+ * @returns {Promise<string>} The base64-encoded CSP hash formatted as 'sha256-...'.
+ */
+async function generateSHA256Hash(text) {
+  if (window.crypto && window.crypto.subtle) {
+    const encoder = new TextEncoder();
+    const data = encoder.encode(text);
+    const hashBuffer = await crypto.subtle.digest("SHA-256", data);
+    const base64Hash = btoa(String.fromCharCode.apply(null, Array.from(new Uint8Array(hashBuffer))));
+    return `sha256-${base64Hash}`;
+  } else {
+    throw new Error(
+      "crypto.subtle is not available. Ensure the test is running in a Secure Context " +
+      "(e.g., loaded over localhost or served with a .https.html extension in WPT)."
+    );
+  }
+}
+
+/**
+ * Returns the exact CSS text content based on the CSP target type.
+ * @param {string} targetType - 'elem' for <style> elements, 'attr' for inline style attributes.
+ * @param {string} className - Unique CSS class name assigned to the MathML element.
+ * @returns {string} Target CSS text.
+ */
+function getStyleContent(targetType, className) {
+  if (targetType === "elem") {
+    return `.${className} { ${TEST_CSS_TEXT} }`;
+  } else if (targetType === "attr") {
+    return TEST_CSS_TEXT;
+  }
+  return "";
+}
+
+/**
+ * Executes a single CSP evaluation for one MathML tag inside an isolated iframe.
+ */
+async function runMathMLCSPTestForTag(t, { 
+  tag, 
+  targetType, 
+  metaPolicyBuilder, 
+  hashShouldMatch = true, 
+  elementModifier = null, 
+  shouldApply 
+}) {
+  const className = `csp-test-${tag.replace(/[^a-zA-Z0-9]/g, "_")}`;
+  const styleContent = getStyleContent(targetType, className);
+
+  // Dynamic Hash generation
+  let hash = "sha256-AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA=";
+  if (metaPolicyBuilder && hashShouldMatch) {
+    hash = await generateSHA256Hash(styleContent);
+  }
+
+  const metaPolicy = metaPolicyBuilder ? metaPolicyBuilder(hash) : null;
+
+  // Render inside isolated iframe
+  const iframe = document.createElement("iframe");
+  document.body.appendChild(iframe);
+  t.add_cleanup(() => iframe.remove());
+
+  const doc = iframe.contentDocument;
+  const metaHtml = metaPolicy ? `<meta http-equiv="Content-Security-Policy" content="${metaPolicy}">` : "";
+
+  doc.open();
+  doc.write(`<!doctype html><html><head>${metaHtml}</head><body><math>${MathMLFragments[tag]}</math></body></html>`);
+  doc.close();
+
+  const mathEl = FragmentHelper.element(doc.body.firstElementChild);
+
+  if (targetType === "attr") {
+    mathEl.setAttribute("style", TEST_CSS_TEXT);
+    if (elementModifier) elementModifier(mathEl);
+  } else if (targetType === "elem") {
+    mathEl.classList.add(className);
+    const styleEl = doc.createElement("style");
+    styleEl.textContent = styleContent;
+    if (elementModifier) elementModifier(styleEl);
+    doc.head.appendChild(styleEl);
+  }
+
+  const computedColor = iframe.contentWindow.getComputedStyle(mathEl).color;
+  const isApplied = computedColor === APPLIED_COLOR_RGB;
+
+  assert_equals(
+    isApplied,
+    shouldApply,
+    `Style application mismatch for <${tag}>. ` +
+    `Computed color: "${computedColor}" (Expected applied: ${shouldApply}). ` +
+    `Policy: [${metaPolicy}], Style Text: [${styleContent}]`
+  );
+}
\ No newline at end of file
diff --git a/third_party/blink/web_tests/external/wpt/svg/styling/svg-element-attributeStyleMap-typed-om.html b/third_party/blink/web_tests/external/wpt/svg/styling/svg-element-attributeStyleMap-typed-om.html
new file mode 100644
index 0000000000000..d44525a2350d2
--- /dev/null
+++ b/third_party/blink/web_tests/external/wpt/svg/styling/svg-element-attributeStyleMap-typed-om.html
@@ -0,0 +1,176 @@
+<!doctype html>
+<meta charset="utf-8">
+<title>SVGElement attributeStyleMap and StylePropertyMap Read/Write Tests</title>
+<link rel="help" href="https://drafts.css-houdini.org/css-typed-om-1/#dom-elementcssinlinestyle-attributestylemap">
+<link rel="help" href="https://drafts.css-houdini.org/css-typed-om-1/#stylepropertymap">
+<script src="/resources/testharness.js"></script>
+<script src="/resources/testharnessreport.js"></script>
+
+<body>
+<div id="svg-container"></div>
+
+<script>
+'use strict';
+
+const SVG_NS = 'http://www.w3.org/2000/svg';
+
+// Comprehensive list of SVG element tags sourced from SVG IDL Harness test (idlharness.window.js)
+const SVG_ELEMENT_TAGS = [
+  'svg', 'g', 'defs', 'desc', 'title', 'symbol', 'use', 'image', 'switch',
+  'style', 'path', 'rect', 'circle', 'ellipse', 'line', 'polyline', 'polygon',
+  'text', 'tspan', 'textPath', 'marker', 'linearGradient', 'radialGradient',
+  'stop', 'pattern', 'clipPath', 'mask', 'a', 'view', 'script', 'animate',
+  'set', 'animateMotion', 'mpath', 'animateTransform', 'metadata',
+  'foreignObject', 'filter', 'feBlend', 'feColorMatrix', 'feComponentTransfer',
+  'feFuncR', 'feFuncG', 'feFuncB', 'feFuncA', 'feComposite', 'feConvolveMatrix',
+  'feDiffuseLighting', 'fePointLight', 'feSpotLight', 'feDisplacementMap',
+  'feDropShadow', 'feFlood', 'feGaussianBlur', 'feImage', 'feMerge',
+  'feMergeNode', 'feMorphology', 'feSpecularLighting', 'feTile', 'feTurbulence'
+];
+
+/**
+ * Safely creates an SVG element for testing.
+ * @param {string} tag 
+ * @returns {SVGElement|null}
+ */
+function createSVGElement(tag) {
+    const container = document.getElementById('svg-container');
+    const el = document.createElementNS(SVG_NS, tag);
+    container.appendChild(el);
+    return el;
+}
+
+// =============================================================================
+// Test Suite 1: Interface & Availability Matrix Across ALL SVG Elements
+// =============================================================================
+for (const tag of SVG_ELEMENT_TAGS) {
+  test(t => {
+    const element = createSVGElement(tag);
+    assert_true(!!element, `SVG element <${tag}> should be created successfully`);
+    t.add_cleanup(() => element.remove());
+
+    assert_true('attributeStyleMap' in element, `attributeStyleMap property should exist on <${tag}>`);
+    const styleMap = element.attributeStyleMap;
+
+    assert_true(!!styleMap, `attributeStyleMap should return a non-null object on <${tag}>`);
+    assert_true(
+      styleMap instanceof StylePropertyMap || styleMap.constructor.name.includes('StylePropertyMap'),
+      `attributeStyleMap should be an instance of StylePropertyMap on <${tag}>`
+    );
+  }, `attributeStyleMap getter exists and returns StylePropertyMap on SVG <${tag}>`);
+}
+
+// =============================================================================
+// Test Suite 2: Read, Write, Delete, and Sync Operations Across ALL SVG Elements
+// =============================================================================
+for (const tag of SVG_ELEMENT_TAGS) {
+  test(t => {
+    const element = createSVGElement(tag);
+    assert_true(!!element, `SVG element <${tag}> should be created successfully`);
+    t.add_cleanup(() => element.remove());
+
+    const styleMap = element.attributeStyleMap;
+
+    // 1. set() operations using standard CSS properties & keywords
+    styleMap.set('opacity', '0.5');
+    styleMap.set('cursor', new CSSKeywordValue('pointer'));
+
+    // 2. has() and get() assertions
+    assert_true(styleMap.has('opacity'), `styleMap.has('opacity') should return true on <${tag}>`);
+    assert_equals(styleMap.get('opacity').toString(), '0.5', `Typed OM 'opacity' mismatch on <${tag}>`);
+    assert_equals(styleMap.get('cursor').value, 'pointer', `Typed OM 'cursor' mismatch on <${tag}>`);
+
+    // 3. Synchronization with DOM CSSStyleDeclaration (element.style)
+    assert_equals(element.style.opacity, '0.5', `Inline style 'opacity' did not sync on <${tag}>`);
+    assert_equals(element.style.cursor, 'pointer', `Inline style 'cursor' did not sync on <${tag}>`);
+
+    // 4. delete() operation
+    styleMap.delete('opacity');
+    assert_false(styleMap.has('opacity'), `styleMap.has('opacity') should return false after delete() on <${tag}>`);
+    assert_equals(element.style.opacity, '', `Inline style 'opacity' should be cleared after delete() on <${tag}>`);
+
+    // 5. clear() operation
+    styleMap.clear();
+    assert_equals(styleMap.size, 0, `styleMap.size should be 0 after clear() on <${tag}>`);
+    assert_equals(element.style.cursor, '', `Inline style 'cursor' should be empty after clear() on <${tag}>`);
+
+  }, `attributeStyleMap set, get, has, delete, and clear sync correctly on <${tag}>`);
+}
+
+// =============================================================================
+// Test Suite 3: List-Valued Properties & getAll()
+// =============================================================================
+test(t => {
+  const element = createSVGElement('rect');
+  t.add_cleanup(() => element.remove());
+  const styleMap = element.attributeStyleMap;
+
+  styleMap.set('transition-duration', CSS.s(1), '200ms');
+
+  const allDurations = styleMap.getAll('transition-duration');
+  assert_equals(allDurations.length, 2, 'getAll() should return array of length 2');
+  assert_equals(allDurations[0].value, 1, 'First duration value should be 1');
+  assert_equals(allDurations[0].unit, 's', 'First duration unit should be "s"');
+  assert_equals(allDurations[1].value, 200, 'Second duration value should be 200');
+  assert_equals(allDurations[1].unit, 'ms', 'Second duration unit should be "ms"');
+
+  assert_equals(element.style.transitionDuration, '1s, 200ms', 'Inline style transitionDuration should sync');
+}, 'attributeStyleMap handles list-valued properties and getAll() on SVGElement');
+
+// =============================================================================
+// Test Suite 4: Custom Properties (CSS Variables) & CSSUnparsedValue
+// =============================================================================
+test(t => {
+  const element = createSVGElement('circle');
+  t.add_cleanup(() => element.remove());
+  const styleMap = element.attributeStyleMap;
+
+  styleMap.set('--svg-fill-color', new CSSUnparsedValue(['#ff0000']));
+  assert_true(styleMap.has('--svg-fill-color'), 'styleMap should contain --svg-fill-color');
+  
+  const customVal = styleMap.get('--svg-fill-color');
+  assert_true(customVal instanceof CSSUnparsedValue, 'Custom property should return CSSUnparsedValue');
+  assert_equals(customVal[0], '#ff0000', 'Custom property string token match');
+
+  styleMap.set('--svg-stroke-width', '4px');
+  assert_equals(element.style.getPropertyValue('--svg-stroke-width').trim(), '4px', 'Custom property should sync with inline style');
+}, 'attributeStyleMap handles custom properties (CSS variables) on SVGElement');
+
+// =============================================================================
+// Test Suite 5: Case Insensitivity
+// =============================================================================
+test(t => {
+  const element = createSVGElement('path');
+  t.add_cleanup(() => element.remove());
+  const styleMap = element.attributeStyleMap;
+
+  styleMap.set('OpAcItY', '0.7');
+  assert_true(styleMap.has('opacity'), 'has() should be case-insensitive');
+  assert_equals(styleMap.get('oPaCiTy').toString(), '0.7', 'get() should be case-insensitive');
+  assert_equals(element.style.opacity, '0.7', 'Inline style opacity should sync');
+}, 'StylePropertyMap methods are case-insensitive on SVGElement');
+
+// =============================================================================
+// Test Suite 6: Error Handling & Invalid Set Operations (TypeError)
+// =============================================================================
+const gInvalidSVGTestCases = [
+  { property: 'invalid-property-name', values: ['value'], desc: 'an unsupported property name' },
+  { property: null, values: ['foo'], desc: 'a null property name' },
+  { property: 'opacity', values: [CSS.deg(90)], desc: 'a unit type mismatch (angle for opacity)' },
+  { property: 'opacity', values: ['10s'], desc: 'an invalid string unit for opacity' },
+];
+
+for (const { property, values, desc } of gInvalidSVGTestCases) {
+  test(t => {
+    const element = createSVGElement('svg');
+    t.add_cleanup(() => element.remove());
+    const styleMap = element.attributeStyleMap;
+
+    assert_throws_js(TypeError, () => {
+      styleMap.set(property, ...values);
+    }, `Setting styleMap with ${desc} should throw TypeError`);
+  }, `StylePropertyMap.set throws TypeError on SVGElement when setting ${desc}`);
+}
+
+</script>
+</body>
\ No newline at end of file

```


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
