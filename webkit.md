# inbox

https://github.com/WebKit/WebKit/commits?author=cathiechen

https://github.com/WebKit/WebKit/commits/main/?author=rniwa

# question template for asking gpt

```bash

I'm reading webkit source code

Which cpp files or class is considered top 10 for understanding webkit and add new web api features, why?


```


# Webkit


flatpak


```bash

// settings

{
    "clangd.path": "/home/tannal/tannalwork/clangd"
}

// clangd
#!/bin/bash
set -eu
# https://stackoverflow.com/a/17841619
function join_by { local d=${1-} f=${2-}; if shift 2; then printf %s "$f" "${@/#/$d}"; fi; }

local_webkit=/home/tannal/tannalwork/projects/WebKit
include_path=("$local_webkit"/WebKitBuild/UserFlatpak/runtime/org.webkit.Sdk/x86_64/*/active/files/include)
if [ ! -f "${include_path[0]}/stdio.h" ]; then
  echo "Couldn't find the directory hosting the /usr/include of the flatpak SDK."
  exit 1
fi
include_path="${include_path[0]}"
mappings=(
  "$local_webkit/WebKitBuild/GTK/Debug=/app/webkit/WebKitBuild/Debug"
  "$local_webkit/WebKitBuild/GTK/Release=/app/webkit/WebKitBuild/Release"
  "$local_webkit=/app/webkit"
  "$include_path=/usr/include"
)

exec "$local_webkit"/Tools/Scripts/webkit-flatpak --gtk --debug run -c clangd --path-mappings="$(join_by , "${mappings[@]}")" "$@"

```

```bash

====================================================================
 WebKit is now built (26m:16s). 
 To run MiniBrowser with this newly-built code, use the
 "Tools/Scripts/run-minibrowser" script.
====================================================================

real	26m16.267s
user	0m0.365s
sys	0m0.111s

sudo apt-get -y install ninja-build

git clone https://github.com/WebKit/WebKit

# install or upgrade flatpak
sudo apt install flatpak

./Tools/Scripts/update-webkit-flatpak

./Tools/Scripts/update-webkitgtk-libs

./Tools/Scripts/build-webkit --gtk --debug --export-compile-commands WK_USE_CCACHE=YES
./Tools/Scripts/build-webkit --gtk --debug WK_USE_CCACHE=YES

usage: 
                  make r EXPORT_COMPILE_COMMANDS=YES
                  generate-compile-commands WebKitBuild/Release

                  https://docs.webkit.org/Build%20%26%20Debug/BuildOptions.html#building-with-compile_commandsjson
                  
generate-compile-commands: error: the following arguments are required: built-products-dir

./Tools/Scripts/run-minibrowser --gtk --debug


ln -s WebKitBuild/GTK/Debug/compile_commands.json compile_commands.json 

rm compile_commands.json 

ln -s ./WebKitBuild/GTK/Debug/DeveloperTools/compile_commands.json compile_commands.json 

import-w3c-tests web-platform-tests/[testsDir] -l -s [wptParentDir] --clean-dest-dir

```

# GPT QA

## Top ten classes to understand webkit

RenderObject (RenderObject.cpp): This class represents a rendered object in the rendering tree. It handles layout, painting, and hit-testing. Understanding how RenderObject works is crucial for comprehending the rendering process in WebKit.

Frame (Frame.cpp): The Frame class represents a web page frame. It manages the lifecycle of a web page, including loading, parsing, and rendering. Understanding Frame is essential for understanding the high-level structure of a web page in WebKit.

Element (Element.cpp): The Element class represents an HTML or XML element in the DOM. It provides methods for accessing and manipulating element properties, attributes, and child nodes. Understanding Element is important for working with HTML and XML content in WebKit.

Document (Document.cpp): The Document class represents an HTML or XML document. It encapsulates the entire DOM tree of a web page and provides methods for accessing and manipulating the document's contents. Understanding Document is crucial for working with web page documents in WebKit.

LayoutState (LayoutState.cpp): The LayoutState class represents the state of the layout process in WebKit. It manages the layout process, including the measurement and positioning of elements on a web page. Understanding LayoutState is important for understanding the layout engine in WebKit.

HTMLParser (HTMLParser.cpp): The HTMLParser class is responsible for parsing HTML documents. It converts raw HTML into a DOM tree structure. Understanding HTMLParser is essential for understanding how HTML parsing works in WebKit.

CSSStyleSelector (CSSStyleSelector.cpp): The CSSStyleSelector class is responsible for resolving CSS styles for elements. It processes CSS rules and applies styles to elements based on selectors and specificity. Understanding CSSStyleSelector is important for understanding how CSS styling is applied in WebKit.

JSDOMWindow (JSDOMWindow.cpp): The JSDOMWindow class represents the JavaScript interface for a DOM window object. It provides methods and properties for interacting with the window and its associated web page. Understanding JSDOMWindow is crucial for understanding the JavaScript integration in WebKit.

NetworkingContext (NetworkingContext.cpp): The NetworkingContext class manages network requests and responses in WebKit. It handles network protocols, caching, cookies, and security. Understanding NetworkingContext is important for understanding the networking aspects of WebKit.

Page (Page.cpp): The Page class represents a web page in WebKit. It manages the top-level components of a web page, including frames, navigation, rendering, and user interactions. Understanding Page is important for understanding the overall structure and functionality of a web page in WebKit.


## new css features

CSSParser (CSSParser.cpp): This class is responsible for parsing CSS stylesheets. It converts CSS code into a structured representation that can be used by the styling engine. Understanding CSSParser is crucial for extending WebKit with new CSS features.

CSSStyleSelector (CSSStyleSelector.cpp): The CSSStyleSelector class applies CSS styles to DOM elements based on the matching selectors. It handles specificity, inheritance, and cascading rules. Understanding CSSStyleSelector is important for implementing and extending CSS styling in WebKit.

RenderStyle (RenderStyle.cpp): The RenderStyle class represents the computed style for a rendered element. It contains information about the visual properties of an element, such as colors, fonts, and layout properties. Understanding RenderStyle is essential for adding and modifying CSS properties in WebKit.

StyleResolver (StyleResolver.cpp): The StyleResolver class resolves the style for DOM elements based on the document's style sheets and the computed style of the parent elements. It interacts with CSSStyleSelector and RenderStyle to apply styles. Understanding StyleResolver is crucial for extending WebKit with new CSS features.

CSSValue (CSSValue.cpp): The CSSValue class represents a single value within a CSS property declaration. It provides methods for parsing and serializing CSS values. Understanding CSSValue is important for handling custom CSS property values.

CSSProperty (CSSProperty.cpp): The CSSProperty class represents a single CSS property. It defines the structure and behavior of individual CSS properties. Understanding CSSProperty is important for adding new CSS properties to WebKit.

CSSStyleDeclaration (CSSStyleDeclaration.cpp): The CSSStyleDeclaration class represents the style declaration for an element. It provides methods for accessing and modifying individual CSS properties on an element. Understanding CSSStyleDeclaration is important for working with CSS properties in WebKit.

RenderBlock (RenderBlock.cpp): The RenderBlock class represents a block-level element in the rendering tree. It handles the layout and rendering of block-level elements, such as <div> and <p>. Understanding RenderBlock is important for understanding the layout and rendering process of block-level elements with new CSS features.

RenderInline (RenderInline.cpp): The RenderInline class represents an inline element in the rendering tree. It handles the layout and rendering of inline-level elements, such as <span> and <a>. Understanding RenderInline is important for understanding the layout and rendering process of inline-level elements with new CSS features.

CSSComputedStyleDeclaration (CSSComputedStyleDeclaration.cpp): The CSSComputedStyleDeclaration class represents the computed style declaration for an element. It provides methods for accessing the final computed values of CSS properties. Understanding CSSComputedStyleDeclaration is important for retrieving and modifying computed styles when adding new CSS features.


## ECMAScript feature in webkit

JSCell (JSCell.cpp): The JSCell class is the base class for all JavaScript objects in WebKit's JavaScriptCore engine. It provides the fundamental structure and behavior for JavaScript objects. Understanding JSCell is crucial for extending WebKit with new ECMAScript features.

JSObject (JSObject.cpp): The JSObject class represents a JavaScript object in WebKit. It provides methods for accessing and manipulating properties, as well as handling object behavior, such as prototypal inheritance. Understanding JSObject is important for working with JavaScript objects in WebKit.

JSGlobalObject (JSGlobalObject.cpp): The JSGlobalObject class represents the global object in JavaScript, which is the root object for all JavaScript code execution. It provides methods and properties that are available globally in JavaScript. Understanding JSGlobalObject is crucial for understanding the global execution environment and scope in WebKit.

JSValue (JSValue.cpp): The JSValue class represents a value in JavaScript, including primitive values, objects, and functions. It provides methods for performing operations and conversions on JavaScript values. Understanding JSValue is important for handling JavaScript values and data types in WebKit.

JSFunction (JSFunction.cpp): The JSFunction class represents a JavaScript function in WebKit. It provides methods for defining and executing JavaScript functions. Understanding JSFunction is crucial for implementing and extending JavaScript function behavior in WebKit.

Parser (Parser.cpp): The Parser class is responsible for parsing JavaScript source code. It converts raw JavaScript code into an abstract syntax tree (AST), which is used for further processing and execution. Understanding Parser is important for extending WebKit with new JavaScript language features.

CodeBlock (CodeBlock.cpp): The CodeBlock class represents compiled JavaScript code in WebKit. It contains the bytecode and metadata needed for executing JavaScript functions. Understanding CodeBlock is crucial for understanding the execution process and optimizing JavaScript code in WebKit.

JSExecState (JSExecState.cpp): The JSExecState class represents the execution state of JavaScript code in WebKit. It provides methods for executing JavaScript code, accessing global objects, and managing the execution context. Understanding JSExecState is important for controlling and managing JavaScript execution in WebKit.

JSAPIWrapperObject (JSAPIWrapperObject.cpp): The JSAPIWrapperObject class is used for bridging JavaScript objects to native code in WebKit. It allows JavaScript code to interact with native APIs and objects. Understanding JSAPIWrapperObject is crucial for integrating new ECMAScript features with native code in WebKit.

JSValueInlines (JSValueInlines.h): The JSValueInlines file contains inline functions that provide efficient access and manipulation of JavaScript values in WebKit. Understanding JSValueInlines is important for optimizing JavaScript value operations and implementing new ECMAScript features efficiently.



## webapi

DOMCoreIncludes.h: This file includes the core DOM classes and files in WebKit. It provides a comprehensive understanding of the DOM (Document Object Model) implementation in WebKit, which is the foundation for various Web API features.

DOMWindow (DOMWindow.cpp): The DOMWindow class represents the global window object in the DOM. It provides methods and properties for interacting with the browser window, including navigation, handling events, and accessing other Web API objects. Understanding DOMWindow is crucial for implementing and extending Web API features that interact with the browser window.

Document (Document.cpp): The Document class represents an HTML or XML document in the DOM. It encapsulates the entire structure of a web page and provides methods for accessing and manipulating its contents. Understanding Document is important for working with the document structure and implementing new Web API features related to document manipulation.

Element (Element.cpp): The Element class represents an HTML or XML element in the DOM. It provides methods for accessing and modifying element properties, attributes, and child nodes. Understanding Element is crucial for implementing and extending Web API features that interact with HTML elements.

XMLHttpRequest (XMLHttpRequest.cpp): The XMLHttpRequest class enables making HTTP requests from JavaScript code. It provides methods for sending requests, handling responses, and managing asynchronous operations. Understanding XMLHttpRequest is important for implementing and extending Web API features related to AJAX and HTTP communication.

Navigator (Navigator.cpp): The Navigator class represents the browser's navigator object in the DOM. It provides information about the user's browser, platform, and capabilities. Understanding Navigator is crucial for implementing and extending Web API features that provide browser-specific information and functionality.

Fetch (Fetch.cpp): The Fetch class handles fetching resources, such as files and URLs, using the Fetch API. It provides methods for making network requests, handling responses, and managing request and response headers. Understanding Fetch is important for implementing and extending Web API features related to network communication.

Event (Event.cpp): The Event class represents an event in the DOM. It provides methods and properties for working with events, including event types, event listeners, and event propagation. Understanding Event is crucial for implementing and extending Web API features related to event handling and interaction.

WebSocket (WebSocket.cpp): The WebSocket class enables creating and managing WebSocket connections from JavaScript code. It provides methods for establishing WebSocket connections, sending and receiving messages, and handling connection events. Understanding WebSocket is important for implementing and extending Web API features related to real-time communication.

MediaStream (MediaStream.cpp): The MediaStream class represents a stream of media content, such as audio or video, in the DOM. It provides methods for capturing and manipulating media streams. Understanding MediaStream is crucial for implementing and extending Web API features related to multimedia processing and streaming.

## domapi

DOMCoreIncludes.h: This file includes the core DOM classes and files in WebKit. It provides a comprehensive understanding of the DOM implementation in WebKit, which is crucial for working with and extending DOM API features.

Node (Node.cpp): The Node class represents a node in the DOM tree hierarchy. It provides methods and properties for working with nodes, such as manipulating their structure, accessing child nodes, and handling events. Understanding Node is essential for implementing and extending DOM API features related to node manipulation and traversal.

Element (Element.cpp): The Element class represents an HTML or XML element in the DOM. It provides methods for accessing and modifying element properties, such as attributes and style. Understanding Element is crucial for implementing and extending DOM API features that interact with HTML elements.

Document (Document.cpp): The Document class represents an HTML or XML document in the DOM. It encapsulates the entire structure of a web page and provides methods for accessing and manipulating its contents. Understanding Document is important for working with the document structure and implementing new DOM API features related to document manipulation.

DOMImplementation (DOMImplementation.cpp): The DOMImplementation class represents the DOM implementation in WebKit. It provides methods for creating various DOM-related objects, such as documents and elements. Understanding DOMImplementation is essential for implementing and extending DOM API features that involve creating and managing DOM objects.

NamedNodeMap (NamedNodeMap.cpp): The NamedNodeMap class represents a collection of nodes associated with an element, usually used for managing element attributes. It provides methods for accessing and manipulating attributes. Understanding NamedNodeMap is important for implementing and extending DOM API features related to attribute handling.

Event (Event.cpp): The Event class represents an event in the DOM. It provides methods and properties for working with events, including event types, event listeners, and event propagation. Understanding Event is crucial for implementing and extending DOM API features related to event handling and interaction.

MutationObserver (MutationObserver.cpp): The MutationObserver class provides a way to react to changes in the DOM tree. It allows observing and responding to mutations, such as node additions or modifications. Understanding MutationObserver is important for implementing and extending DOM API features that involve monitoring and reacting to DOM changes.

Range (Range.cpp): The Range class represents a portion of the document selected by the user or programmatically. It provides methods for manipulating the selected range, such as extracting or modifying its contents. Understanding Range is crucial for implementing and extending DOM API features related to text selection and manipulation.

XPathEvaluator (XPathEvaluator.cpp): The XPathEvaluator class provides methods for evaluating XPath expressions on an XML document. It allows querying XML data using XPath syntax. Understanding XPathEvaluator is important for implementing and extending DOM API features that involve XPath-based querying and manipulation of XML documents.


## webgl/webgl2/webgpu

WebGLRenderingContext (WebGLRenderingContext.cpp): The WebGLRenderingContext class represents the WebGL 1.0 API context in WebKit. It provides methods for interacting with the WebGL graphics API, such as setting up the rendering context, creating and manipulating WebGL objects, and issuing rendering commands. Understanding WebGLRenderingContext is crucial for implementing and extending WebGL API features.

WebGL2RenderingContext (WebGL2RenderingContext.cpp): The WebGL2RenderingContext class represents the WebGL 2.0 API context in WebKit. It extends the functionality of WebGLRenderingContext and provides additional methods and features introduced in WebGL 2.0. Understanding WebGL2RenderingContext is important for implementing and extending WebGL 2.0 API features.

WebGPURenderingContext (WebGPURenderingContext.cpp): The WebGPURenderingContext class represents the WebGPU API context in WebKit. It provides methods for interacting with the WebGPU graphics API, such as setting up the rendering context, creating and manipulating WebGPU objects, and issuing rendering commands. Understanding WebGPURenderingContext is crucial for implementing and extending WebGPU API features.

GraphicsContext (GraphicsContext.cpp): The GraphicsContext class is a low-level graphics rendering context in WebKit. It provides methods for rendering 2D graphics primitives and managing graphics resources. Understanding GraphicsContext is important for implementing and extending low-level graphics functionality in WebGL, WebGL2, and WebGPU.

GraphicsContext3D (GraphicsContext3D.cpp): The GraphicsContext3D class provides a hardware-accelerated 3D graphics context in WebKit. It is used as a base class for WebGLRenderingContext and WebGL2RenderingContext. Understanding GraphicsContext3D is crucial for implementing and extending the underlying 3D graphics functionality in WebGL and WebGL2.

WebGLRenderingContextBase (WebGLRenderingContextBase.cpp): The WebGLRenderingContextBase class is a base class for both WebGLRenderingContext and WebGL2RenderingContext. It provides common functionality and shared methods between the two WebGL contexts. Understanding WebGLRenderingContextBase is important for understanding the common behavior and functionality of WebGL and WebGL2.

WebGLRenderingContextAttributes (WebGLRenderingContextBase.cpp): The WebGLRenderingContextAttributes class represents the context attributes for a WebGL rendering context. It includes properties such as the alpha, depth, and stencil settings. Understanding WebGLRenderingContextAttributes is important for configuring and managing the WebGL rendering context.

Extensions3D (Extensions3D.cpp): The Extensions3D class provides an interface for enabling and using WebGL extensions. WebGL extensions introduce additional features and capabilities beyond the core WebGL API. Understanding Extensions3D is crucial for implementing and extending WebGL extensions and their associated functionality.

WebGLVertexArrayObjectOES (WebGLVertexArrayObjectOES.cpp): The WebGLVertexArrayObjectOES class represents the OES_vertex_array_object extension in WebGL. It provides methods for creating and manipulating vertex array objects, which encapsulate vertex attribute configurations. Understanding WebGLVertexArrayObjectOES is important for implementing and extending vertex array object functionality in WebGL.

WebGL2RenderingContextBase (WebGL2RenderingContextBase.cpp): The WebGL2RenderingContextBase class is a base class for WebGL2RenderingContext. It provides common functionality and shared methods specific to WebGL 2.0. Understanding WebGL2RenderingContextBase is important for understanding the common behavior and functionality of WebGL 2.0.


## css grid

RenderGrid (RenderGrid.cpp): The RenderGrid class represents the rendering object for CSS Grid containers in WebKit. It handles the layout and rendering of grid items within a grid container. Understanding RenderGrid is crucial for implementing and extending CSS Grid functionality in WebKit.

GridTrackSize (GridTrackSize.cpp): The GridTrackSize class represents the size of a grid track in CSS Grid. It defines the size and behavior of a track, such as its width or height and whether it's flexible or fixed. Understanding GridTrackSize is important for implementing and extending CSS Grid track sizing in WebKit.

GridTrackSizingAlgorithm (GridTrackSizingAlgorithm.cpp): The GridTrackSizingAlgorithm class provides methods for calculating the sizes of grid tracks based on the CSS Grid layout algorithm. It handles the logic for resolving track sizes and handling various constraints. Understanding GridTrackSizingAlgorithm is crucial for understanding the layout algorithm and implementing new CSS Grid features related to track sizing.

GridTrackSizeBuilder (GridTrackSizeBuilder.cpp): The GridTrackSizeBuilder class is responsible for parsing and building grid track sizes from CSS declarations. It converts the CSS syntax into GridTrackSize objects that can be used for layout. Understanding GridTrackSizeBuilder is important for understanding the parsing and conversion of CSS Grid track sizes in WebKit.

GridArea (GridArea.cpp): The GridArea class represents a grid area in CSS Grid. It defines the position and span of an item within the grid container. Understanding GridArea is crucial for implementing and extending CSS Grid item placement and spanning in WebKit.

GridAreaGroup (GridAreaGroup.cpp): The GridAreaGroup class provides methods for grouping grid areas and managing their placement within the grid container. It handles the logic for resolving conflicts and positioning items within the grid. Understanding GridAreaGroup is important for understanding the placement and positioning of grid items in WebKit.

GridContainerData (GridContainerData.cpp): The GridContainerData class represents the internal data structure for a CSS Grid container. It stores information about the grid tracks, grid areas, and other properties of the grid. Understanding GridContainerData is crucial for understanding the internal representation of a CSS Grid container in WebKit.

RenderGridArea (RenderGridArea.cpp): The RenderGridArea class represents the rendering object for a CSS Grid item within a grid container. It handles the layout and rendering of the item within its assigned grid area. Understanding RenderGridArea is important for implementing and extending the rendering and layout of grid items in WebKit.

GridTrackSizeValue (GridTrackSizeValue.cpp): The GridTrackSizeValue class represents a single value within a grid track size declaration in CSS. It provides methods for parsing and manipulating the value, such as extracting the numeric portion or converting it to a string. Understanding GridTrackSizeValue is important for handling individual track size values in CSS Grid.

RenderGridIterator (RenderGridIterator.cpp): The RenderGridIterator class provides methods for iterating over grid tracks and grid areas within a CSS Grid container. It allows traversal and inspection of the grid structure. Understanding RenderGridIterator is crucial for implementing and extending iteration and traversal of grid tracks and areas in WebKit.

## css flex

RenderFlexibleBox (RenderFlexibleBox.cpp): The RenderFlexibleBox class represents the rendering object for CSS Flexbox containers in WebKit. It handles the layout and rendering of flex items within a flex container. Understanding RenderFlexibleBox is crucial for implementing and extending CSS Flexbox functionality in WebKit.

BoxAlignmentData (BoxAlignmentData.cpp): The BoxAlignmentData class provides methods for handling box alignment properties in CSS Flexbox. It handles the alignment and positioning of flex items within a flex container. Understanding BoxAlignmentData is important for implementing and extending box alignment features in WebKit.

RenderFlexibleBoxIterator (RenderFlexibleBoxIterator.cpp): The RenderFlexibleBoxIterator class provides methods for iterating over flex items within a CSS Flexbox container. It allows traversal and inspection of the flex items. Understanding RenderFlexibleBoxIterator is crucial for implementing and extending iteration and traversal of flex items in WebKit.

RenderFlexibleBoxFlexDistribution (RenderFlexibleBoxFlexDistribution.cpp): The RenderFlexibleBoxFlexDistribution class handles the distribution of available space among flex items in a CSS Flexbox container. It implements the flex distribution algorithm as specified in the CSS Flexbox specification. Understanding RenderFlexibleBoxFlexDistribution is important for implementing and extending the flex distribution behavior in WebKit.

RenderFlexibleBoxFlexGroup (RenderFlexibleBoxFlexGroup.cpp): The RenderFlexibleBoxFlexGroup class provides methods for grouping flex items and managing their flex properties within a CSS Flexbox container. It handles the logic for resolving flex conflicts and applying flex properties to flex items. Understanding RenderFlexibleBoxFlexGroup is crucial for understanding the flex property handling in WebKit.

RenderFlexibleBoxFlexItem (RenderFlexibleBoxFlexItem.cpp): The RenderFlexibleBoxFlexItem class represents the rendering object for a flex item within a CSS Flexbox container. It handles the layout and rendering of the flex item within the flex container. Understanding RenderFlexibleBoxFlexItem is important for implementing and extending the rendering and layout of flex items in WebKit.

RenderFlexibleBoxUtils (RenderFlexibleBoxUtils.cpp): The RenderFlexibleBoxUtils class provides utility methods for handling various aspects of CSS Flexbox layout, such as measuring and positioning flex items. It encapsulates common functionality used throughout the Flexbox implementation in WebKit. Understanding RenderFlexibleBoxUtils is crucial for understanding the utility functions and common operations in WebKit's CSS Flexbox implementation.

FlexLayoutAlgorithm (FlexLayoutAlgorithm.cpp): The FlexLayoutAlgorithm class implements the layout algorithm for CSS Flexbox containers. It handles the determination of flex item sizes, positioning, and spacing within the flex container. Understanding FlexLayoutAlgorithm is important for implementing and extending the layout algorithm for CSS Flexbox in WebKit.

RenderFlexibleBoxDeprecatedFlexibleBox (RenderFlexibleBoxDeprecatedFlexibleBox.cpp): The RenderFlexibleBoxDeprecatedFlexibleBox class provides compatibility support for the deprecated version of CSS Flexible Box Layout. It handles the rendering and layout of flex items within a deprecated flex container. Understanding RenderFlexibleBoxDeprecatedFlexibleBox is crucial for understanding the deprecated Flexbox implementation in WebKit.

FlexboxLayoutEngine (FlexboxLayoutEngine.cpp): The FlexboxLayoutEngine class provides methods for calculating and applying the layout of CSS Flexbox containers. It encapsulates the overall layout engine responsible for flex container layout. Understanding FlexboxLayoutEngine is important for understanding the high-level layout process and coordinating the layout of flex containers and flex items in WebKit.

## bigInt js feature

JSCJSValue.h and JSCJSValue.cpp: These files define the core JavaScript value representation in WebKit's JavaScriptCore engine. Understanding how JavaScript values are stored and manipulated is crucial for working with BigInt and extending JavaScript capabilities in WebKit.

BigIntConstructor.h and BigIntConstructor.cpp: These files define the BigInt constructor function in JavaScriptCore. They handle the creation and initialization of BigInt objects. Understanding these files is important for adding new features to the BigInt constructor and expanding the capabilities of BigInt in WebKit.

BigIntObject.h and BigIntObject.cpp: These files define the BigInt object in JavaScriptCore. They handle the behavior and operations of BigInt instances. Understanding these files is crucial for adding new methods and functionalities to BigInt objects in WebKit.

BigIntPrototype.h and BigIntPrototype.cpp: These files define the prototype object for BigInt in JavaScriptCore. They handle the implementation of built-in methods and properties available on BigInt instances. Understanding these files is important for adding new prototype methods and properties to BigInt in WebKit.

BigInt.h and BigInt.cpp: These files define the BigInt data type itself in JavaScriptCore. They handle the representation, manipulation, and arithmetic operations of BigInt values. Understanding these files is crucial for understanding the internals of BigInt and implementing new BigInt features in WebKit.

JITBigInt.h and JITBigInt.cpp: These files define the just-in-time (JIT) compilation support for BigInt operations in JavaScriptCore. They handle the generation of optimized machine code for BigInt arithmetic. Understanding these files is important for optimizing BigInt performance and extending the JIT support for new BigInt features in WebKit.

BigIntOperations.h and BigIntOperations.cpp: These files provide utility functions for performing low-level operations on BigInt values in JavaScriptCore. They handle operations such as addition, subtraction, multiplication, and division. Understanding these files is crucial for implementing low-level BigInt operations and extending the capabilities of BigInt in WebKit.

BigIntPrototypeFunctions.h and BigIntPrototypeFunctions.cpp: These files define additional built-in functions that can be called on BigInt instances in JavaScriptCore. They handle the implementation of functions like toString and valueOf for BigInt objects. Understanding these files is important for adding new built-in functions to BigInt instances in WebKit.

BigIntMath.h and BigIntMath.cpp: These files provide utility functions for performing mathematical operations with BigInt values in JavaScriptCore. They handle operations such as square roots, exponentiation, and modular arithmetic. Understanding these files is crucial for implementing advanced mathematical operations with BigInt and extending the math capabilities of BigInt in WebKit.

BigIntJSON.h and BigIntJSON.cpp: These files handle the serialization and deserialization of BigInt values in JavaScriptCore. They provide functions for converting BigInt values to JSON strings and parsing JSON strings into BigInt values. Understanding these files is important for ensuring proper interoperability of BigInt with JSON in WebKit.

## class field feature

JSCJSValue.h and JSCJSValue.cpp: These files define the core JavaScript value representation in WebKit's JavaScriptCore engine. Understanding how JavaScript values are stored and manipulated is crucial for working with class fields and extending JavaScript capabilities in WebKit.

JSCustomGetterSetterFunctions.h and JSCustomGetterSetterFunctions.cpp: These files handle the implementation of custom getter and setter functions in JavaScriptCore. They provide the infrastructure to define custom behavior for accessing and modifying class fields. Understanding these files is important for adding support for custom getters and setters to class fields in WebKit.

JSClassRef.h and JSClassRef.cpp: These files define the structure and behavior of JavaScript classes in JavaScriptCore. They handle the registration of class fields and methods, as well as the instantiation of JavaScript objects. Understanding these files is crucial for adding support for class fields and extending the class definition capabilities in WebKit.

JSObject.h and JSObject.cpp: These files define the base JavaScript object representation in JavaScriptCore. They handle the storage and retrieval of properties, including class fields, on JavaScript objects. Understanding these files is important for adding support for class fields to JavaScript objects in WebKit.

JSPropertyNameEnumerator.h and JSPropertyNameEnumerator.cpp: These files provide functionality for enumerating the properties of JavaScript objects in JavaScriptCore. They handle the enumeration of class fields and other properties. Understanding these files is crucial for implementing property enumeration with class fields in WebKit.

Parser.h and Parser.cpp: These files handle the parsing and syntax analysis of JavaScript code in WebKit. They define the grammar rules and parse tree generation for JavaScript programs. Understanding these files is important for extending the parser to handle class field declarations and syntax in WebKit.

Nodes.h and Nodes.cpp: These files define the abstract syntax tree (AST) nodes used in JavaScriptCore. They represent the various syntactic constructs of JavaScript, including class field declarations. Understanding these files is crucial for adding support for class fields to the AST and extending the AST traversal and manipulation capabilities in WebKit.

CodeBlock.h and CodeBlock.cpp: These files handle the compilation and execution of JavaScript code in JavaScriptCore. They represent the compiled bytecode and provide mechanisms for executing JavaScript programs. Understanding these files is important for integrating class fields into the compilation and execution pipeline of JavaScript code in WebKit.

JSGlobalObject.h and JSGlobalObject.cpp: These files define the global object in JavaScriptCore. They handle the creation and initialization of the global environment, including the registration of global variables and functions. Understanding these files is crucial for integrating class fields into the global object and extending the global environment with class field support in WebKit.

JSClass.h and JSClass.cpp: These files define the structure and behavior of JavaScript classes in JavaScriptCore. They handle the registration of class fields, static fields, and static methods. Understanding these files is important for adding support for class fields and extending the class definition capabilities in WebKit.

##  WPE WebKit

WPELoaderClient.h and WPELoaderClient.cpp: These files define the loader client for the WPE port of WebKit. They handle the loading and initialization of web content, including resource loading and navigation. Understanding these files is crucial for integrating and extending the loading capabilities of the WPE WebKit port.

WPEView.h and WPEView.cpp: These files define the view component for the WPE port. They handle the rendering and display of web content, including managing the viewport and handling user input events. Understanding these files is important for extending the visual rendering capabilities of the WPE WebKit port.

WPEAPICast.h: This file provides convenience functions and macros for casting WPE-specific types, such as WPEView, to their WebKit equivalents. Understanding this file is important for interacting with WebKit APIs and integrating new features into the WPE WebKit port.

WPELauncherMain.cpp: This file contains the entry point for the WPELauncher, which is a sample application for running the WPE WebKit port. It initializes the necessary components and sets up the main loop for handling user interaction and rendering. Understanding this file is important for understanding the overall structure and initialization process of the WPE WebKit port.

WPEWebKit.h and WPEWebKit.cpp: These files define the public interface for the WPE WebKit port. They provide functions and classes for initializing and configuring the port, as well as accessing various WebKit functionalities. Understanding these files is crucial for integrating new features into the WPE WebKit port and interacting with WebKit APIs.

WPEWebKitPrivate.h and WPEWebKitPrivate.cpp: These files contain private implementation details and internal functions for the WPE WebKit port. They handle low-level operations and provide utilities and helpers specific to the WPE port. Understanding these files is important for extending and customizing the behavior of the WPE WebKit port.

WPEWebPage.h and WPEWebPage.cpp: These files define the web page component for the WPE port. They handle the creation and management of web page instances, including handling navigation, JavaScript execution, and interaction with the DOM. Understanding these files is crucial for extending the web page capabilities of the WPE WebKit port.

WPEWebKitWebView.h and WPEWebKitWebView.cpp: These files define the web view component for the WPE port. They handle the creation and management of web view instances, including managing multiple web pages, handling view settings, and coordinating the interactions between the view and the underlying WebKit engine. Understanding these files is important for extending the view capabilities of the WPE WebKit port.

WPEWebInspectorServer.h and WPEWebInspectorServer.cpp: These files define the web inspector server component for the WPE port. They handle the setup and communication with the web inspector, enabling developers to inspect and debug web content running in the WPE WebKit port. Understanding these files is crucial for extending the debugging capabilities of the WPE WebKit port.

WPEBackend.h and WPEBackend.cpp: These files define the backend component for the WPE port. They handle the platform-specific integration, such as input handling, rendering, and event loop integration. Understanding these files is important for extending and customizing the low-level platform integration of the WPE WebKit port.


# MathML

RenderMathMLRoot.h and RenderMathMLRoot.cpp: These files define the rendering logic for the MathML <math> element, which represents the root of a MathML expression. Understanding these files is crucial for understanding how MathML expressions are rendered and displayed in WebKit.

MathMLNames.h and MathMLNames.cpp: These files define the MathML element names and their corresponding IDs in WebKit. They provide the necessary constants and mappings for identifying and handling MathML elements. Understanding these files is important for integrating new MathML elements and extending the MathML support in WebKit.

MathMLTextElement.cpp and MathMLTextElement.h: These files define the representation and handling of MathML text elements, such as <mi>, <mo>, and <mn>. They handle the rendering and layout of MathML text content. Understanding these files is crucial for rendering MathML text elements correctly and extending the text handling capabilities in WebKit.

MathMLMathElement.cpp and MathMLMathElement.h: These files define the representation and handling of the MathML <math> element. They handle the parsing and rendering of MathML expressions, as well as the layout and positioning of MathML content. Understanding these files is important for integrating new MathML features and extending the rendering capabilities of MathML expressions in WebKit.

MathMLOperators.cpp and MathMLOperators.h: These files define the rendering and handling of MathML operators, such as <mo>. They handle the layout and positioning of MathML operators and their associated properties. Understanding these files is crucial for correctly rendering MathML operators and extending the operator handling capabilities in WebKit.

MathMLTokenElement.cpp and MathMLTokenElement.h: These files define the representation and handling of MathML token elements, such as <mi> and <mo>. They handle the rendering and layout of MathML token content. Understanding these files is important for rendering MathML token elements correctly and extending the token handling capabilities in WebKit.

MathMLInlineContainer.cpp and MathMLInlineContainer.h: These files define the representation and handling of MathML inline containers, such as <mrow>, <mfrac>, and <msqrt>. They handle the layout and positioning of MathML inline content. Understanding these files is crucial for correctly rendering MathML inline containers and extending the inline content handling capabilities in WebKit.

MathMLBlockContainer.cpp and MathMLBlockContainer.h: These files define the representation and handling of MathML block containers, such as <mtable>, <mtr>, and <mtd>. They handle the layout and positioning of MathML block content. Understanding these files is important for correctly rendering MathML block containers and extending the block content handling capabilities in WebKit.

MathMLElement.cpp and MathMLElement.h: These files define the base class for MathML elements in WebKit. They provide common functionality and properties for MathML elements. Understanding these files is crucial for extending the MathML element hierarchy and adding new MathML element types to WebKit.

MathMLRenderSupport.cpp and MathMLRenderSupport.h: These files provide support functions and utilities for rendering MathML content in WebKit. They handle tasks such as font selection, layout calculations, and rendering optimizations for MathML elements. Understanding these files is important for optimizing the rendering performance of MathML content and extending the rendering capabilities in WebKit.

# webkit/webcore



```cpp
// ContainerNode.cpp
// In the DOM, a container node is a node that can have child nodes. Examples of container nodes include elements like <div>, <ul>, and <table>. The ContainerNode class provides common functionality and operations for manipulating and managing child nodes within these container elements.

// Comment.cpp
// It contains various algorithms and utility functions related to manipulating and traversing the Document Object Model (DOM) nodes.

<!-- This is a comment -->

// Source/WebCore/dom/ContentVisibilityAutoStateChangeEvent.cpp
// Automatic content visibility is a feature introduced in WebKit to improve the performance and power efficiency of web browsing. It allows the browser engine to automatically adjust the rendering and resource allocation for content that is not currently visible to the user. For example, when a webpage is scrolled out of view or hidden behind other windows, the automatic content visibility feature can reduce the processing and rendering overhead for that content.

// The ContentVisibilityAutoStateChangeEvent class is used to represent events that occur when the automatic content visibility state of a webpage changes. It provides information about the affected content and the new visibility state.


```

rendering and layout, JavaScript execution, networking, and handling HTML and CSS parsing.

The hard part of learning is the "bootstrap" problem (like compilers).

These series tell you some part of webkit project on how it works.

And How it interract with other parts?

I think the existing knowledge can lead you learn more.

## WebKit/Source/JavaScriptCore/heap/LocalAllocator.cpp

This is webkit memory allocator

## heap/ -> runtime/

js Runtime use allocateCell to allocate memory for js objects

runtime/ include allocateCell

There is a common practice that member variable with prefix 'm_' which indicates it's scope.

## runtime/

vmEntryToJavaScript

js_trampoline_op_call

heap::addToRememberedSet

for minor gc add old space objects with hold reference to the eden space, we need these objects be treated like gc roots.




# reference

https://blogs.igalia.com/aboya/2021/10/02/setting-up-visualstudio-code-to-work-with-webkitgtk-using-clangd/