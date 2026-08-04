

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
