# Floyd's cycle-finding algorithm

```js
const floyd = (f, x0) => {

    let tortoise = f(x0);
    let hare = f(f(x0));

    while (tortoise !== hare) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }

    let mu = 0;
    tortoise = x0;
    while (tortoise !== hare) {
        tortoise = f(tortoise);
        hare = f(hare);
        mu += 1;
    }

    let lam = 1;
    hare = f(tortoise);
    while (tortoise !== hare) {
        hare = f(hare);
        lam += 1;
    }

    return [mu, lam];

}

// test case 1
let f = (x) => (x + 1) % 7;
let x0 = 0;
console.log(floyd(f, x0)); // [0, 7]

// test case 2
f = (x) => (x + 1) % 5;
x0 = 0;
console.log(floyd(f, x0)); // [0, 5]

// test case 3
f = (x) => (x + 1) % 3;
x0 = 0;
console.log(floyd(f, x0)); // [0, 3]

// complex test case 1
f = (x) => (x + 1) % 7;
x0 = 3;
console.log(floyd(f, x0)); // [3, 4]


// complex test case 2
f = (x) => (x + 1) %10 + 5;
x0 = 0;
console.log(floyd(f, x0)); // [0, 1]

console.log(f(0))
console.log(f(f(0)))
console.log(f(f(f(0))))
console.log(f(f(f(f(0)))))
console.log(f(f(f(f(f(0))))))
console.log(f(f(f(f(f(f(0)))))))
console.log(f(f(f(f(f(f(f(0))))))))
console.log(f(f(f(f(f(f(f(f(0)))))))))

```

# parallel odd even bubble sort in golang

```go

package main

func swap(i, j int, array []int) {
	temp := array[i]
	array[i] = array[j]
	array[j] = temp
}

func thread(array []int, start int, end int, ch chan bool) {
	for i := start; i < end; i += 2 {
		if array[i] > array[i+1] {
			swap(i, i+1, array)
			ch <- false
		}
	}

	ch <- true
}

func oldEventSort(array []int) []int {
	sorted := false
	evenSorted := make(chan bool)
	oddSorted := make(chan bool)

	for !sorted {

		sorted = true

		go thread(array, 0, len(array)-1, evenSorted)

		go thread(array, 1, len(array)-1, oddSorted)

		sorted = <-evenSorted && <-oddSorted
	}

	return array
}

func main() {
	// test case 1
	array := []int{5, 3, 8, 6, 2, 7, 1, 4}
	array = oldEventSort(array)
	// expected output: [1 2 3 4 5 6 7 8]
	for i := 0; i < len(array); i++ {
		print(array[i], " ")
	}
	println()

	// test case 2
	array = []int{5, 3, 8, 6, 2, 7, 1, 4, 9}
	array = oldEventSort(array)
	// expected output: [1 2 3 4 5 6 7 8 9]
	for i := 0; i < len(array); i++ {
		print(array[i], " ")
	}
	println()

	// test case 3
	array = []int{5, 3, 8, 6, 2, 7, 1, 4, 9, 0}
	array = oldEventSort(array)
	// expected output: [0 1 2 3 4 5 6 7 8 9]
	for i := 0; i < len(array); i++ {
		print(array[i], " ")
	}
	println()

	// complex test case 4
	array = []int{5, 3, 8, 6, 2, 7, 1, 4, 9, 0, 10, 15, 13, 12, 11, 14}
	array = oldEventSort(array)
	// expected output: [0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15]
	for i := 0; i < len(array); i++ {
		print(array[i], " ")
	}

	println()

	// simple test case 1
	array = []int{5, 3, 8, 6, 2, 7, 1, 4, 9, 0, 10, 15, 13, 12, 11, 14, 16}
	array = oldEventSort(array)
	// expected output: [0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16]
	for i := 0; i < len(array); i++ {
		print(array[i], " ")
	}
	println()

	// edge case 1
	array = []int{5}
	array = oldEventSort(array)
	// expected output: [5]
	for i := 0; i < len(array); i++ {
		print(array[i], " ")
	}
	println()

	// edge case 2
	array = []int{}
	array = oldEventSort(array)
	// expected output: []
	for i := 0; i < len(array); i++ {
		print(array[i], " ")
	}
	println()

	// big test case 1
	array = []int{5, 3, 8, 6, 2, 7, 1, 4, 9, 0, 10, 15, 13, 12, 11, 14, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28}
	array = oldEventSort(array)
	// expected output: [0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28]
	for i := 0; i < len(array); i++ {
		print(array[i], " ")
	}
	println()
}


```

# bubble sort

```js

const bubbleSort = (array) => {
    let n = array.length;
    
    let swapped = false;

    do{

        swapped = false;

        for(let i = 1; i < n; i++){
            if(array[i - 1] > array[i]){
                let temp = array[i];
                array[i] = array[i-1];
                array[i-1] = temp;
                swapped = true;
            }
        }

        console.log(array)

    }while(swapped)

    return array
}


const bubbleSort2 = (array) => {

    for(let n = array.length; n > 1; ){

        // n is the biggest index of the unsorted part of the array
        console.log(array[n])

        let newN = 0
        for(let i = 1; i < n; i++){
            if(array[i - 1] > array[i]){
                let temp = array[i];
                array[i] = array[i-1];
                array[i-1] = temp;
                newN = i;
            }
        }
        n = newN;
    }

    return array
}


// test case 1
let array = [5, 3, 8, 2, 1, 4]
console.log(bubbleSort(array)) // [1, 2, 3, 4, 5, 8]


// test case 2
array = [20, 20, 31, 56, 1, 12, 12]
console.log(bubbleSort2(array)) // [1, 12, 12, 20, 20, 31, 56]

```

# html tokenizer

```python

def tokenize(html_input):
    # Regular expressions for identifying different types of tokens
    start_tag_pattern = r'<[^/][^>]*>'
    end_tag_pattern = r'</[^>]*>'
    text_content_pattern = r'[^<]+'

    # Combine the patterns into a single regular expression
    combined_pattern = f'({start_tag_pattern})|({end_tag_pattern})|({text_content_pattern})'

    # Tokenize the HTML input
    tokens = re.findall(combined_pattern, html_input)

    # Flatten the list of tuples and remove empty strings
    tokens = [token for tup in tokens for token in tup if token]

    return tokens

```

# OpenCV install

```bash
VERSION=4.8.0

test -e ${VERSION}.zip || wget https://github.com/opencv/opencv/archive/refs/tags/${VERSION}.zip
test -e opencv-${VERSION} || unzip ${VERSION}.zip

test -e opencv_extra_${VERSION}.zip || wget -O opencv_extra_${VERSION}.zip https://github.com/opencv/opencv_contrib/archive/refs/tags/${VERSION}.zip
test -e opencv_contrib-${VERSION} || unzip opencv_extra_${VERSION}.zip


cd opencv-${VERSION}
mkdir build
cd build

cmake -D CMAKE_BUILD_TYPE=RELEASE \
-D CMAKE_INSTALL_PREFIX=/usr/local \
-D WITH_TBB=ON \
-D ENABLE_FAST_MATH=1 \
-D CUDA_FAST_MATH=1 \
-D WITH_CUBLAS=1 \
-D WITH_CUDA=ON \
-D BUILD_opencv_cudacodec=ON \
-D WITH_CUDNN=ON \
-D OPENCV_DNN_CUDA=ON \
-D WITH_QT=OFF \
-D WITH_OPENGL=ON \
-D BUILD_opencv_apps=OFF \
-D BUILD_opencv_python2=OFF \
-D OPENCV_GENERATE_PKGCONFIG=ON \
-D OPENCV_PC_FILE_NAME=opencv.pc \
-D OPENCV_ENABLE_NONFREE=ON \
-D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-${VERSION}/modules \
-D INSTALL_PYTHON_EXAMPLES=OFF \
-D INSTALL_C_EXAMPLES=OFF \
-D BUILD_EXAMPLES=OFF \
-D CUDA_ARCH_BIN=8.6 \
-D WITH_FFMPEG=ON \
-D CUDNN_INCLUDE_DIR=/usr/local/cuda/include \
-D CUDNN_LIBRARY=/usr/local/cuda/lib64/libcudnn.so \
..

make -j 8
sudo make -j 8 install

```

# Modern Web Application

```html

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ChatGGG</title>
    <!-- faceicon.svg -->
    <link rel="icon" href="./favicon.svg" type="image/svg+xml">
    <!-- <link rel=stylesheet href="./quill.css" async defer> -->
    <link rel=stylesheet href="//cdn.quilljs.com/1.3.6/quill.snow.css" async defer>
    <link rel=stylesheet href="//cdnjs.cloudflare.com/ajax/libs/KaTeX/0.7.1/katex.min.css" async defer>
    <link rel=stylesheet href="//cdnjs.cloudflare.com/ajax/libs/highlight.js/9.12.0/styles/monokai-sublime.min.css"
        async defer>
    <script src="https://cdn.tailwindcss.com?plugins=forms,typography,aspect-ratio,line-clamp"></script>
    <script type="importmap">
    {
      "imports": {
        "markdown-it": "https://esm.sh/markdown-it@14.0.0",
        "react": "https://esm.sh/stable/react@18.2.0/",
        "react-router": "https://esm.sh/react-router@6.22.3",
        "react-router-dom": "https://esm.sh/react-router-dom@6.22.3",
        "react-dom": "https://esm.sh/react-dom@18.2.0/",
        "tailwindcss": "https://esm.sh/tailwindcss@3.4.1",
        "vue": "https://unpkg.com/vue@3/dist/vue.esm-browser.js",
        "svelte": "https://esm.sh/svelte@4.2.12",
        "solid-js": "https://esm.sh/solid-js@1.8.15",
        "lit-html": "https://esm.sh/lit-html@3.1.2",
        "y-indexeddb": "/y-indexeddb.js",
        "quill": "https://esm.sh/quill@1.3.7",
        "yjs": "https://esm.sh/yjs@13.6.10",
        "y-websocket": "/y-websocket.js",
        "quill-cursors": "https://esm.sh/quill-cursors@4.0.2",
        "y-quill": "/y-quill.js"
      }
    }
    </script>
    <style>
        [v-cloak] {
            display: none;
        }

        #container {
            width: 863px;
            height: 600px;
        }
    </style>
</head>

<body>
    <button type="button" id="y-connect-btn">Disconnect</button>
    <p></p>
    <p>This is a demo of the <a href="https://github.com/yjs/yjs">Yjs</a> ⇔ <a href="https://quilljs.com/">Quill</a>
        binding: <a href="https://github.com/yjs/y-quill">y-quill</a>.</p>
    <p>The content of this editor is shared with every client that visits this domain.</p>

    <script type="module">
        import * as Y from 'yjs'
        import { WebsocketProvider } from 'y-websocket'
        import { QuillBinding } from 'y-quill'
        import Quill from 'quill'
        import QuillCursors from 'quill-cursors'
        import { IndexeddbPersistence } from 'y-indexeddb'

        Quill.register('modules/cursors', QuillCursors)

        window.addEventListener('load', () => {
            const ydoc = new Y.Doc()
            const provider = new WebsocketProvider(
                'ws://192.168.43.246:1234/', // use the public ws server
                // `ws${location.protocol.slice(4)}//${location.host}/ws`, // alternatively: use the local ws server (run `npm start` in root directory)
                'quill-demo-6',
                ydoc
            )
            const indexeddbProvider = new IndexeddbPersistence('y-indexeddb', ydoc)
            const ytext = ydoc.getText('quill')
            const editorContainer = document.createElement('div')
            editorContainer.setAttribute('id', 'editor')
            document.body.insertBefore(editorContainer, null)

            const editor = new Quill(editorContainer, {
                modules: {
                    cursors: true,
                    toolbar: [
                        [{ header: [1, 2, false] }],
                        ['bold', 'italic', 'underline'],
                        ['image', 'code-block']
                    ],
                    history: {
                        userOnly: true
                    }
                },
                placeholder: 'Start collaborating...',
                theme: 'snow' // or 'bubble'
            })

            const binding = new QuillBinding(ytext, editor, provider.awareness)

            /*
            // Define user name and user name
            // Check the quill-cursors package on how to change the way cursors are rendered
            provider.awareness.setLocalStateField('user', {
              name: 'Typing Jimmy',
              color: 'blue'
            })
            */

            const connectBtn = document.getElementById('y-connect-btn')
            connectBtn.addEventListener('click', () => {
                if (provider.shouldConnect) {
                    provider.disconnect()
                    connectBtn.textContent = 'Connect'
                } else {
                    provider.connect()
                    connectBtn.textContent = 'Disconnect'
                }
            })

            // @ts-ignore
            window.example = { provider, ydoc, ytext, binding, Y }
        })
    </script>
</body>

</html>

```

# GTK

```c
#include <gtk/gtk.h>

static void add_task(GtkWidget *widget, gpointer data);
static void remove_task(GtkWidget *widget, gpointer data);



void activate(GtkApplication* app, gpointer user_data) {
    GtkWidget *window, *listbox, *add_button, *entry, *scrolled_window;
    GtkWidget *vbox, *hbox; // Vertical and horizontal boxes for layout

    // Create a new window, and set its title
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "To-Do List");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    // Vertical box for holding the main UI elements
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Scrolled window for the listbox
    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(scrolled_window, 200, 150);
    gtk_box_pack_start(GTK_BOX(vbox), scrolled_window, TRUE, TRUE, 0);

    // Listbox for tasks
    listbox = gtk_list_box_new();
    gtk_container_add(GTK_CONTAINER(scrolled_window), listbox);

    // Horizontal box for input and add button
    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, TRUE, 0);

    // Task entry field
    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), entry, TRUE, TRUE, 0);

    // Add task button
    add_button = gtk_button_new_with_label("Add Task");
    gtk_box_pack_start(GTK_BOX(hbox), add_button, FALSE, TRUE, 0);

    // Connect the "clicked" event of the button to the callback function
    g_signal_connect(add_button, "clicked", G_CALLBACK(add_task), entry);

    // Remove task button, placed outside of hbox for simplicity
    GtkWidget *remove_button = gtk_button_new_with_label("Remove Selected Task");
    gtk_box_pack_start(GTK_BOX(vbox), remove_button, FALSE, TRUE, 0);

    // Connect the "clicked" event of the button to the callback function
    g_signal_connect(remove_button, "clicked", G_CALLBACK(remove_task), listbox);

    gtk_widget_show_all(window);
}

static void add_task(GtkWidget *widget, gpointer data) {
    const char *task_text = gtk_entry_get_text(GTK_ENTRY(data));
    if (task_text[0] == '\0') return; // Don't add empty tasks

    GtkWidget *row = gtk_list_box_row_new();
    GtkWidget *label = gtk_label_new(task_text);
    gtk_container_add(GTK_CONTAINER(row), label);
    gtk_container_add(GTK_CONTAINER(gtk_widget_get_parent(widget)), row);

    gtk_widget_show_all(gtk_widget_get_parent(widget));

    gtk_entry_set_text(GTK_ENTRY(data), ""); // Clear entry field
}

static void remove_task(GtkWidget *widget, gpointer data) {
    GtkListBox *listbox = GTK_LIST_BOX(data);
    GtkListBoxRow *row = gtk_list_box_get_selected_row(listbox);

    if (row != NULL) {
        gtk_widget_destroy(GTK_WIDGET(row));
    }
}

int main(int argc, char *argv[]) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.todo", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
```

# Modern Web development

esbuild

```html

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ChatGGG</title>
    <!-- faceicon.svg -->
    <link rel="icon" href="./favicon.svg" type="image/svg+xml">
    <script src="https://cdn.tailwindcss.com?plugins=forms,typography,aspect-ratio,line-clamp"></script>
    <script type="importmap">
    {
      "imports": {
        "markdown-it": "https://esm.sh/markdown-it@14.0.0",
        "react": "https://esm.sh/stable/react@18.2.0/",
        "react-router": "https://esm.sh/react-router@6.22.3",
        "react-router-dom": "https://esm.sh/react-router-dom@6.22.3",
        "react-dom": "https://esm.sh/react-dom@18.2.0/",
        "tailwindcss": "https://esm.sh/tailwindcss@3.4.1",
        "vue": "https://unpkg.com/vue@3/dist/vue.esm-browser.js",
        "svelte": "https://esm.sh/svelte@4.2.12",
        "solid-js": "https://esm.sh/solid-js@1.8.15",
        "lit-html": "https://esm.sh/lit-html@3.1.2"
      }
    }
    </script>
    <style>
        [v-cloak] {
            display: none;
        }

        #container {
            width: 863px;
            height: 600px;
        }
    </style>
</head>

<body>
    <div id="app"></div>
    <div v-cloak id="app-vue" class="text-red-200">
        {{ message }}
    </div>
    <div id="container"></div>
    <script type="module" src="./app.js"></script>
    <script type="module">
        import { App, Counter } from './app.js';
        import ReactDOM from "react-dom";
        import markdownit from "markdown-it";
        ReactDOM.createRoot(document.querySelector('#app')).render(App());

        import * as monaco from 'https://esm.sh/monaco-editor';
        import editorWorker from 'https://esm.sh/monaco-editor/esm/vs/editor/editor.worker?worker';
        import jsonWorker from 'https://esm.sh/monaco-editor/esm/vs/language/json/json.worker?worker';
        import cssWorker from 'https://esm.sh/monaco-editor/esm/vs/language/css/css.worker?worker';
        import htmlWorker from 'https://esm.sh/monaco-editor/esm/vs/language/html/html.worker?worker';
        import tsWorker from 'https://esm.sh/monaco-editor/esm/vs/language/typescript/ts.worker?worker';

        self.MonacoEnvironment = {
            getWorker(_, label) {
                if (label === 'json') {
                    return new jsonWorker();
                }
                if (label === 'css' || label === 'scss' || label === 'less') {
                    return new cssWorker();
                }
                if (label === 'html' || label === 'handlebars' || label === 'razor') {
                    return new htmlWorker();
                }
                if (label === 'typescript' || label === 'javascript') {
                    return new tsWorker();
                }
                return new editorWorker();
            }
        };
        monaco.editor.create(document.getElementById('container'), {
            value: ['function x() {', '\tconsole.log("Hello world!");', '}'].join('\n'),
            language: 'javascript'
        });
    </script>

    <script type="module">
        import { createApp, ref } from 'vue'

        createApp({
            setup() {
                const message = ref('Hello Vue!')
                return {
                    message
                }
            }
        }).mount('#app-vue')
    </script>
</body>

</html>

```

# WebGL threejs

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <title>Hello World WebGL</title>
    <style>
        body {
            margin: 0;
        }

        canvas {
            display: block;
        }
    </style>
</head>

<body>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/three.js/r128/three.min.js"></script>
    <script>
        // Create an empty scene
        var scene = new THREE.Scene();

        // Create a basic perspective camera
        var camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
        camera.position.z = 4;

        // Create a renderer with Antialiasing
        var renderer = new THREE.WebGLRenderer({ antialias: true });

        // Configure renderer clear color
        renderer.setClearColor("#000000");

        // Configure renderer size
        renderer.setSize(window.innerWidth, window.innerHeight);

        // Append Renderer to DOM
        document.body.appendChild(renderer.domElement);

        // ------------------------------------------------
        // FUN STARTS HERE
        // ------------------------------------------------

        // Create a Cube Mesh with basic material
        var geometry = new THREE.BoxGeometry(1, 1, 1);
        var material = new THREE.MeshBasicMaterial({ color: "#433F81" });
        var cube = new THREE.Mesh(geometry, material);

        // Add cube to Scene
        scene.add(cube);

        // Render Loop
        var render = function () {
            requestAnimationFrame(render);

            cube.rotation.x += 0.01;
            cube.rotation.y += 0.01;

            // Render the scene
            renderer.render(scene, camera);
        };

        render();
    </script>
</body>

</html>
```

# tokenier in c

```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Token types
typedef enum {
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    PUNCTUATION,
    INCREMENT,
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    char value[50]; // Adjust the size as needed
} Token;

// Function to check if a string is a keyword
int isKeyword(const char *word) {
    const char *keywords[] = {"int", "void", "return", "if", "else", "while", "for"};
    const int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1; // It's a keyword
        }
    }

    return 0; // Not a keyword
}

// Function to tokenize a C code
void tokenize(const char *code) {
    char buffer[50]; // Adjust the size as needed
    int bufferIndex = 0;

    for (size_t i = 0; i < strlen(code); i++) {
        char currentChar = code[i];

        if (isalnum(currentChar) || currentChar == '_') {
            // Collect characters for keywords or identifiers
            buffer[bufferIndex++] = currentChar;
        } else {
            // Handle non-alphanumeric characters
            if (bufferIndex > 0) {
                buffer[bufferIndex] = '\0';
                Token token;

                if (isKeyword(buffer)) {
                    token.type = KEYWORD;
                } else {
                    token.type = IDENTIFIER;
                }

                strcpy(token.value, buffer);
                printf("%s '%s'\n", token.type == KEYWORD ? "keyword" : "identifier", token.value);
                // Reset buffer
                bufferIndex = 0;
            }

            // Handle + - * / ( ) { } ; = characters
            if (currentChar == '+' || currentChar == '-') {
                // increment or decrement
                if (code[i + 1] == currentChar) {
                    Token token;
                    token.type = INCREMENT;
                    token.value[0] = currentChar;
                    token.value[1] = currentChar;
                    token.value[2] = '\0';
                    printf("increment '%s'\n", token.value);
                    i++;
                } else {
                    Token token;
                    token.type = OPERATOR;
                    token.value[0] = currentChar;
                    token.value[1] = '\0';
                    printf("operator '%s'\n", token.value);
                }
            } else if (currentChar == '(' || currentChar == ')' || currentChar == '{' || currentChar == '}' || currentChar == ';') {
                Token token;
                token.type = PUNCTUATION;
                token.value[0] = currentChar;
                token.value[1] = '\0';
                printf("punctuation '%s'\n", token.value);
            } else if (currentChar == '=') {
                Token token;
                token.type = OPERATOR;
                token.value[0] = currentChar;
                token.value[1] = '\0';
                printf("operator '%s'\n", token.value);
            } else if (currentChar == '+') {
                Token token;
                token.type = INCREMENT;
                token.value[0] = currentChar;
                token.value[1] = currentChar;
                token.value[2] = '\0';
                printf("increment '%s'\n", token.value);
            }
        }
    }
}

int main() {
    const char *inputCode = "int a, b;\nint c;\nvoid func(int x) {\n    a++;\n}";

    // Tokenize the input code
    tokenize(inputCode);

    return 0;
}

```

# WebGPU shader

```html

<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
  <title>webgpu-samples: helloTriangle</title>
  <style>
    :root {
      color-scheme: light dark;
    }

    html,
    body {
      margin: 0;
      /* remove default margin */
      height: 100%;
      /* make body fill the browser window */
      display: flex;
      place-content: center center;
    }

    canvas {
      width: 600px;
      height: 600px;
      max-width: 100%;
      display: block;
    }
  </style>
  <script type="module">
    var triangleVertWGSL = `@vertex
fn main(
  @builtin(vertex_index) VertexIndex : u32
) -> @builtin(position) vec4f {
  var pos = array<vec2f, 3>(
    vec2(0.0, 0.5),
    vec2(-0.5, -0.5),
    vec2(0.5, -0.5)
  );

  return vec4f(pos[VertexIndex], 0.0, 1.0);
}
`;

    var redFragWGSL = `@fragment
fn main() -> @location(0) vec4f {
  return vec4(1.0, 0.0, 0.0, 1.0);
}`;

    const canvas = document.querySelector('canvas');
    const adapter = await navigator.gpu.requestAdapter();
    const device = await adapter.requestDevice();
    const context = canvas.getContext('webgpu');
    const devicePixelRatio = window.devicePixelRatio;
    canvas.width = canvas.clientWidth * devicePixelRatio;
    canvas.height = canvas.clientHeight * devicePixelRatio;
    const presentationFormat = navigator.gpu.getPreferredCanvasFormat();
    context.configure({
      device,
      format: presentationFormat,
      alphaMode: 'premultiplied',
    });
    const pipeline = device.createRenderPipeline({
      layout: 'auto',
      vertex: {
        module: device.createShaderModule({
          code: triangleVertWGSL,
        }),
      },
      fragment: {
        module: device.createShaderModule({
          code: redFragWGSL,
        }),
        targets: [
          {
            format: presentationFormat,
          },
        ],
      },
      primitive: {
        topology: 'triangle-list',
      },
    });
    function frame() {
      const commandEncoder = device.createCommandEncoder();
      const textureView = context.getCurrentTexture().createView();
      const renderPassDescriptor = {
        colorAttachments: [
          {
            view: textureView,
            clearValue: { r: 0.0, g: 0.0, b: 0.0, a: 1.0 },
            loadOp: 'clear',
            storeOp: 'store',
          },
        ],
      };
      const passEncoder = commandEncoder.beginRenderPass(renderPassDescriptor);
      passEncoder.setPipeline(pipeline);
      passEncoder.draw(3);
      passEncoder.end();
      device.queue.submit([commandEncoder.finish()]);
      requestAnimationFrame(frame);
    }
    requestAnimationFrame(frame);
    //# sourceMappingURL=main.js.map

  </script>
</head>

<body>
  <canvas></canvas>
</body>

</html>

```

# linux system programming wav file reading

```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct WaveHeader{
    int riff_id;
    int riff_sz;
    int riff_fmt;
    int fmt_id;
    int fmt_sz;
    short audio_fmt;
    short num_chn;
    int sample_rate;
    int byte_rate;                                                                                                                                                                                          
    short block_align;
    short bits_per_sample;
    int data_id;
    int data_sz;
} WaveHeader;
 
int main(void)
{
	FILE *stream;
	WaveHeader wh;
 
	memset(&wh, 0x00, sizeof(wh));
 
	printf("sizeof(WaveHeader) = %ld.\n", sizeof(WaveHeader));
 
	if((stream=fopen("startup.wav","ro"))==NULL)
	{
		fprintf(stderr,"Can not open file.\n");
		return 0;
	}
	printf("open success.\n");
 
	fseek(stream, 0, SEEK_SET);
 
	fread(&wh,1,sizeof(wh),stream);
 
	fclose(stream);
	
	printf("riff_id %d,\n" \
			"riff_size %d\n" \
			"num_chn %d.\n" \
			"sample_rate %d.\n" \
			"byte_rate %d.\n" \
			"block_align %d.\n" \
			, wh.riff_id, wh.riff_sz, wh.num_chn, wh.sample_rate, wh.byte_rate, wh.block_align);
 
	return 0;
}

```

# cuda example

#include <iostream>

// Kernel definition
__global__ void matrixAdd(const float* A, const float* B, float* C, int Nx, int Ny) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;
    if (i < Nx && j < Ny) {
        int index = j * Nx + i;
        C[index] = A[index] + B[index];
    }
}

int main() {
    // Matrix dimensions
    const int Nx = 12;
    const int Ny = 6;

    // Allocate host memory
    float* h_A = new float[Nx * Ny];
    float* h_B = new float[Nx * Ny];
    float* h_C = new float[Nx * Ny];

    // Initialize host arrays
    // ... (code to fill in h_A and h_B with data)

    // Allocate device memory
    float *d_A, *d_B, *d_C;
    cudaMalloc(&d_A, Nx * Ny * sizeof(float));
    cudaMalloc(&d_B, Nx * Ny * sizeof(float));
    cudaMalloc(&d_C, Nx * Ny * sizeof(float));

    // Copy data from host to device
    cudaMemcpy(d_A, h_A, Nx * Ny * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, Nx * Ny * sizeof(float), cudaMemcpyHostToDevice);

    // Kernel launch
    dim3 threadsPerBlock(4, 3);
    dim3 numBlocks((Nx + threadsPerBlock.x - 1) / threadsPerBlock.x,
                   (Ny + threadsPerBlock.y - 1) / threadsPerBlock.y);
    matrixAdd<<<numBlocks, threadsPerBlock>>>(d_A, d_B, d_C, Nx, Ny);

    // Copy result back to host
    cudaMemcpy(h_C, d_C, Nx * Ny * sizeof(float), cudaMemcpyDeviceToHost);

    // Free device memory
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    // Free host memory
    delete[] h_A;
    delete[] h_B;
    delete[] h_C;

    return 0;
}

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(matrix_add LANGUAGES CXX CUDA)

# Specify the executable and its source file
add_executable(matrix_add matrix_add.cu)

# Specify the C++ standard
set_target_properties(matrix_add PROPERTIES
                      CUDA_SEPARABLE_COMPILATION ON
                      CXX_STANDARD 14
                      CXX_STANDARD_REQUIRED ON)


# hash join

```go

package main

import (
	"fmt"
)

// Define the struct for table rows
type TableRowR struct {
	id    int
	value int
}

type TableRowS struct {
	id    int
	cdate string
	value int
}

// Define the struct for the join result
type JoinResult struct {
	R_id    int
	S_cdate string
}

// Mock data for tables R and S
var tableR = []TableRowR{
	{id: 1, value: 50},
	{id: 2, value: 120},
	{id: 3, value: 150},
}

var tableS = []TableRowS{
	{id: 2, cdate: "2024-02-16", value: 200},
	{id: 3, cdate: "2024-02-15", value: 90},
	{id: 4, cdate: "2024-02-14", value: 300},
}

// Step 1: Projection
func projectR(rows []TableRowR) []int {
	var projection []int
	for _, row := range rows {
		projection = append(projection, row.id)
	}
	return projection
}

// Step 2: Build hash table for the join
func buildHashTable(rows []TableRowR) map[int]TableRowR {
	hashTable := make(map[int]TableRowR)
	for _, row := range rows {
		hashTable[row.id] = row
	}
	return hashTable
}

// Step 3: Perform the join
func hashJoin(rHashTable map[int]TableRowR, sRows []TableRowS) []JoinResult {
	var results []JoinResult
	for _, sRow := range sRows {
		if rRow, ok := rHashTable[sRow.id]; ok {
			results = append(results, JoinResult{R_id: rRow.id, S_cdate: sRow.cdate})
		}
	}
	return results
}

// Step 4: Filter S by value
func filterS(rows []TableRowS) []TableRowS {
	var filtered []TableRowS
	for _, row := range rows {
		if row.value > 10 {
			filtered = append(filtered, row)
		}
	}
	return filtered
}

func main() {

	// Materialize hash table of R based on projection
	rHashTable := buildHashTable(tableR)

	// Materialize filtered S
	filteredS := filterS(tableS)

	// Perform join and materialize the result
	joinResults := hashJoin(rHashTable, filteredS)

	// Print the join results
	for _, result := range joinResults {
		fmt.Printf("R.id: %d, S.cdate: %s\n", result.R_id, result.S_cdate)
	}
}

```

# Automatic Diffe

```go

package main

import (
	"fmt"
	"math"
)

// Define a struct to hold the value and derivative
type AD struct {
	Value, Derivative float64
}

// Define operations for automatic differentiation
func (ad AD) Multiply(other AD) AD {
	return AD{
		Value:      ad.Value * other.Value,
		Derivative: ad.Value*other.Derivative + ad.Derivative*other.Value,
	}
}

func (ad AD) Add(other AD) AD {
	return AD{
		Value:      ad.Value + other.Value,
		Derivative: ad.Derivative + other.Derivative,
	}
}

func (ad AD) Subtract(other AD) AD {
	return AD{
		Value:      ad.Value - other.Value,
		Derivative: ad.Derivative - other.Derivative,
	}
}

func Log(ad AD) AD {
	return AD{
		Value:      math.Log(ad.Value),
		Derivative: ad.Derivative / ad.Value,
	}
}

func Sin(ad AD) AD {
	return AD{
		Value:      math.Sin(ad.Value),
		Derivative: ad.Derivative * math.Cos(ad.Value),
	}
}

func main() {
	// Initialize x1 and x2 with their values and derivatives
	// Since we are differentiating with respect to x1, its derivative is 1
	x1 := AD{Value: 2, Derivative: 1}
	// x2 is treated as a constant with respect to x1, so its derivative is 0
	x2 := AD{Value: 5, Derivative: 0}

	// Compute the function and its derivative using the chain rule
	v3 := Log(x1)
	v4 := x1.Multiply(x2)
	v5 := Sin(x2)
	v6 := v3.Add(v4)
	v7 := v6.Subtract(v5)

	fmt.Printf("The value of the function is: %.3f\n", v7.Value)
	fmt.Printf("The derivative of the function with respect to x1 is: %.3f\n", v7.Derivative)
}

```

# http proxy

$env:HTTP_PROXY = "http://127.0.0.1:7890"
$env:HTTPS_PROXY = "http://127.0.0.1:7890"

set http_proxy=http://192.168.43.1:7890
set https_proxy=http://192.168.43.1:7890

set http_proxy=hhttp://127.0.0.1:7890
set https_proxy=http://127.0.0.1:7890

$env:HTTP_PROXY = "http://192.168.43.1:7890"
$env:HTTPS_PROXY = "http://192.168.43.1:7890"

# ci cd pipeline for deno

```yml
# GENERATED BY ./ci.generate.ts -- DO NOT DIRECTLY EDIT

name: ci
on:
  push:
    branches:
      - main
    tags:
      - '*'
  pull_request:
    types:
      - opened
      - reopened
      - synchronize
      - ready_for_review
concurrency:
  group: '${{ github.workflow }}-${{ !contains(github.event.pull_request.labels.*.name, ''ci-test-flaky'') && github.head_ref || github.run_id }}'
  cancel-in-progress: true
jobs:
  pre_build:
    name: pre-build
    runs-on: ubuntu-latest
    outputs:
      skip_build: '${{ steps.check.outputs.skip_build }}'
    steps:
      - name: Configure git
        run: |-
          git config --global core.symlinks true
          git config --global fetch.parallel 32
        if: github.event.pull_request.draft == true
      - name: Clone repository
        uses: actions/checkout@v3
        with:
          fetch-depth: 5
          submodules: false
        if: github.event.pull_request.draft == true
      - id: check
        run: |-
          GIT_MESSAGE=$(git log --format=%s -n 1 ${{github.event.after}})
          echo Commit message: $GIT_MESSAGE
          echo $GIT_MESSAGE | grep '\[ci\]' || (echo 'Exiting due to draft PR. Commit with [ci] to bypass.' ; echo 'skip_build=true' >> $GITHUB_OUTPUT)
        if: github.event.pull_request.draft == true
  build:
    name: '${{ matrix.job }} ${{ matrix.profile }} ${{ matrix.os_display_name }}'
    needs:
      - pre_build
    if: '${{ needs.pre_build.outputs.skip_build != ''true'' }}'
    runs-on: '${{ matrix.runner || matrix.os }}'
    timeout-minutes: 120
    defaults:
      run:
        shell: bash
    strategy:
      matrix:
        include:
          - os: macos-12
            job: test
            profile: debug
            os_display_name: macos-x86_64
          - os: macos-12
            job: test
            profile: release
            skip: '${{ !contains(github.event.pull_request.labels.*.name, ''ci-full'') && (github.event_name == ''pull_request'') }}'
            runner: '${{ (!contains(github.event.pull_request.labels.*.name, ''ci-full'') && (github.event_name == ''pull_request'')) && ''ubuntu-22.04'' || ''macos-12'' }}'
            os_display_name: macos-x86_64
          - os: macos-13-xlarge
            job: test
            profile: release
            skip: '${{ !contains(github.event.pull_request.labels.*.name, ''ci-full'') && (github.event_name == ''pull_request'' || github.ref == ''refs/heads/main'') }}'
            runner: '${{ (!contains(github.event.pull_request.labels.*.name, ''ci-full'') && (github.event_name == ''pull_request'' || github.ref == ''refs/heads/main'')) && ''ubuntu-22.04'' || ''macos-13-xlarge'' }}'
            os_display_name: macos-aarch64
          - os: windows-2022
            job: test
            profile: debug
            os_display_name: windows-x86_64
          - os: '${{ github.repository == ''denoland/deno'' && ''windows-2022-xl'' || ''windows-2022'' }}'
            job: test
            profile: release
            skip: '${{ !contains(github.event.pull_request.labels.*.name, ''ci-full'') && (github.event_name == ''pull_request'') }}'
            runner: '${{ (!contains(github.event.pull_request.labels.*.name, ''ci-full'') && (github.event_name == ''pull_request'')) && ''ubuntu-22.04'' || github.repository == ''denoland/deno'' && ''windows-2022-xl'' || ''windows-2022'' }}'
            os_display_name: windows-x86_64
          - os: '${{ github.repository == ''denoland/deno'' && ''ubuntu-22.04-xl'' || ''ubuntu-22.04'' }}'
            job: test
            profile: release
            use_sysroot: true
            wpt: '${{ !startsWith(github.ref, ''refs/tags/'') }}'
            os_display_name: ubuntu-x86_64
          - os: '${{ github.repository == ''denoland/deno'' && ''ubuntu-22.04-xl'' || ''ubuntu-22.04'' }}'
            job: bench
            profile: release
            use_sysroot: true
            skip: '${{ !contains(github.event.pull_request.labels.*.name, ''ci-full'') && (github.event_name == ''pull_request'' && !contains(github.event.pull_request.labels.*.name, ''ci-bench'')) }}'
            runner: '${{ (!contains(github.event.pull_request.labels.*.name, ''ci-full'') && (github.event_name == ''pull_request'' && !contains(github.event.pull_request.labels.*.name, ''ci-bench''))) && ''ubuntu-22.04'' || github.repository == ''denoland/deno'' && ''ubuntu-22.04-xl'' || ''ubuntu-22.04'' }}'
            os_display_name: ubuntu-x86_64
          - os: ubuntu-22.04
            job: test
            profile: debug
            use_sysroot: true
            os_display_name: ubuntu-x86_64
          - os: ubuntu-22.04
            job: lint
            profile: debug
            os_display_name: ubuntu-x86_64
          - os: macos-12
            job: lint
            profile: debug
            os_display_name: macos-x86_64
          - os: windows-2022
            job: lint
            profile: debug
            os_display_name: windows-x86_64
      fail-fast: '${{ github.event_name == ''pull_request'' || (github.ref != ''refs/heads/main'' && !startsWith(github.ref, ''refs/tags/'')) }}'
    env:
      CARGO_TERM_COLOR: always
      RUST_BACKTRACE: full
      RUST_LIB_BACKTRACE: 0
    steps:
      - name: Reconfigure Windows Storage
        if: '!(matrix.skip) && (startsWith(matrix.os, ''windows'') && !endsWith(matrix.os, ''-xl''))'
        shell: pwsh
        run: |-
          New-Item -ItemType "directory" -Path "$env:TEMP/__target__"
          New-Item -ItemType Junction -Target "$env:TEMP/__target__" -Path "D:/a/deno/deno"
      - name: Configure git
        run: |-
          git config --global core.symlinks true
          git config --global fetch.parallel 32
        if: '!(matrix.skip)'
      - name: Clone repository
        uses: actions/checkout@v3
        with:
          fetch-depth: 5
          submodules: false
        if: '!(matrix.skip)'
      - name: Clone submodule ./test_util/std
        run: git submodule update --init --recursive --depth=1 -- ./test_util/std
        if: '!(matrix.skip)'
      - name: Clone submodule ./test_util/wpt
        run: git submodule update --init --recursive --depth=1 -- ./test_util/wpt
        if: '!(matrix.skip) && (matrix.wpt)'
      - name: Clone submodule ./tools/node_compat/node
        run: git submodule update --init --recursive --depth=1 -- ./tools/node_compat/node
        if: '!(matrix.skip) && (matrix.job == ''lint'' && startsWith(matrix.os, ''ubuntu''))'
      - name: 'Create source tarballs (release, linux)'
        if: |-
          !(matrix.skip) && (startsWith(matrix.os, 'ubuntu') &&
          matrix.profile == 'release' &&
          matrix.job == 'test' &&
          github.repository == 'denoland/deno' &&
          startsWith(github.ref, 'refs/tags/'))
        run: |-
          mkdir -p target/release
          tar --exclude=".git*" --exclude=target --exclude=third_party/prebuilt \
              -czvf target/release/deno_src.tar.gz -C .. deno
      - uses: dsherret/rust-toolchain-file@v1
        if: '!(matrix.skip)'
      - if: '!(matrix.skip) && (matrix.job == ''lint'' || matrix.job == ''test'' || matrix.job == ''bench'')'
        name: Install Deno
        uses: denoland/setup-deno@v1
        with:
          deno-version: v1.x
      - name: Install Python
        uses: actions/setup-python@v4
        with:
          python-version: 3.11
        if: '!(matrix.skip) && (matrix.job != ''lint'')'
      - name: Remove unused versions of Python
        if: '!(matrix.skip) && (matrix.job != ''lint'' && (startsWith(matrix.os, ''windows'')))'
        shell: pwsh
        run: |-
          $env:PATH -split ";" |
            Where-Object { Test-Path "$_\python.exe" } |
            Select-Object -Skip 1 |
            ForEach-Object { Move-Item "$_" "$_.disabled" }
      - if: '!(matrix.skip) && (matrix.job == ''bench'')'
        name: Install Node
        uses: actions/setup-node@v3
        with:
          node-version: 18
      - name: Install protoc
        uses: arduino/setup-protoc@v2
        with:
          version: '21.12'
          repo-token: '${{ secrets.GITHUB_TOKEN }}'
        if: '!(matrix.skip)'
      - if: |-
          !(matrix.skip) && (matrix.profile == 'release' &&
          matrix.job == 'test' &&
          github.repository == 'denoland/deno' &&
          (github.ref == 'refs/heads/main' ||
          startsWith(github.ref, 'refs/tags/')))
        name: Authenticate with Google Cloud
        uses: google-github-actions/auth@v1
        with:
          project_id: denoland
          credentials_json: '${{ secrets.GCP_SA_KEY }}'
          export_environment_variables: true
          create_credentials_file: true
      - name: Setup gcloud (unix)
        if: |-
          !(matrix.skip) && (runner.os != 'Windows' &&
          matrix.profile == 'release' &&
          matrix.job == 'test' &&
          github.repository == 'denoland/deno' &&
          (github.ref == 'refs/heads/main' ||
          startsWith(github.ref, 'refs/tags/')))
        uses: google-github-actions/setup-gcloud@v1
        with:
          project_id: denoland
      - name: Setup gcloud (windows)
        if: |-
          !(matrix.skip) && (runner.os == 'Windows' &&
          matrix.profile == 'release' &&
          matrix.job == 'test' &&
          github.repository == 'denoland/deno' &&
          (github.ref == 'refs/heads/main' ||
          startsWith(github.ref, 'refs/tags/')))
        uses: google-github-actions/setup-gcloud@v1
        env:
          CLOUDSDK_PYTHON: '${{env.pythonLocation}}\python.exe'
        with:
          project_id: denoland
      - name: Configure canary build
        if: |-
          !(matrix.skip) && (matrix.job == 'test' &&
          matrix.profile == 'release' &&
          github.repository == 'denoland/deno' &&
          github.ref == 'refs/heads/main')
        run: echo "DENO_CANARY=true" >> $GITHUB_ENV
      - if: '!(matrix.skip) && (matrix.use_sysroot)'
        name: Set up incremental LTO and sysroot build
        run: |-
          # Avoid running man-db triggers, which sometimes takes several minutes
          # to complete.
          sudo apt-get remove --purge -y man-db
          # Remove older clang before we install
          sudo apt-get remove 'clang-12*' 'clang-13*' 'clang-14*' 'clang-15*' 'llvm-12*' 'llvm-13*' 'llvm-14*' 'llvm-15*' 'lld-12*' 'lld-13*' 'lld-14*' 'lld-15*'

          # Install clang-XXX, lld-XXX, and debootstrap.
          echo "deb http://apt.llvm.org/jammy/ llvm-toolchain-jammy-16 main" |
            sudo dd of=/etc/apt/sources.list.d/llvm-toolchain-jammy-16.list
          curl https://apt.llvm.org/llvm-snapshot.gpg.key |
            gpg --dearmor                                 |
          sudo dd of=/etc/apt/trusted.gpg.d/llvm-snapshot.gpg
          sudo apt-get update
          # this was unreliable sometimes, so try again if it fails
          sudo apt-get install --no-install-recommends debootstrap clang-16 lld-16 clang-tools-16 clang-format-16 clang-tidy-16 || echo 'Failed. Trying again.' && sudo apt-get clean && sudo apt-get update && sudo apt-get install --no-install-recommends debootstrap clang-16 lld-16 clang-tools-16 clang-format-16 clang-tidy-16
          # Fix alternatives
          (yes '' | sudo update-alternatives --force --all) || true

          # Create ubuntu-16.04 sysroot environment, which is used to avoid
          # depending on a very recent version of glibc.
          # `libc6-dev` is required for building any C source files.
          # `file` and `make` are needed to build libffi-sys.
          # `curl` is needed to build rusty_v8.
          sudo debootstrap                                     \
            --include=ca-certificates,curl,file,libc6-dev,make \
            --no-merged-usr --variant=minbase xenial /sysroot  \
            http://azure.archive.ubuntu.com/ubuntu
          sudo mount --rbind /dev /sysroot/dev
          sudo mount --rbind /sys /sysroot/sys
          sudo mount --rbind /home /sysroot/home
          sudo mount -t proc /proc /sysroot/proc

          wget https://github.com/denoland/deno_third_party/raw/master/prebuilt/linux64/libdl/libdl.a
          wget https://github.com/denoland/deno_third_party/raw/master/prebuilt/linux64/libdl/libdl.so.2

          sudo ln -s libdl.so.2 /sysroot/lib/x86_64-linux-gnu/libdl.so
          sudo ln -s libdl.a /sysroot/lib/x86_64-linux-gnu/libdl.a

          # Configure the build environment. Both Rust and Clang will produce
          # llvm bitcode only, so we can use lld's incremental LTO support.
          cat >> $GITHUB_ENV << __0
          CARGO_PROFILE_BENCH_INCREMENTAL=false
          CARGO_PROFILE_BENCH_LTO=false
          CARGO_PROFILE_RELEASE_INCREMENTAL=false
          CARGO_PROFILE_RELEASE_LTO=false
          RUSTFLAGS<<__1
            -C linker-plugin-lto=true
            -C linker=clang-16
            -C link-arg=-fuse-ld=lld-16
            -C link-arg=--sysroot=/sysroot
            -C link-arg=-ldl
            -C link-arg=-Wl,--allow-shlib-undefined
            -C link-arg=-Wl,--thinlto-cache-dir=$(pwd)/target/release/lto-cache
            -C link-arg=-Wl,--thinlto-cache-policy,cache_size_bytes=700m
            --cfg tokio_unstable
            ${{ env.RUSTFLAGS }}
          __1
          RUSTDOCFLAGS<<__1
            -C linker-plugin-lto=true
            -C linker=clang-16
            -C link-arg=-fuse-ld=lld-16
            -C link-arg=--sysroot=/sysroot
            -C link-arg=-ldl
            -C link-arg=-Wl,--allow-shlib-undefined
            -C link-arg=-Wl,--thinlto-cache-dir=$(pwd)/target/release/lto-cache
            -C link-arg=-Wl,--thinlto-cache-policy,cache_size_bytes=700m
            ${{ env.RUSTFLAGS }}
          __1
          CC=clang-16
          CFLAGS=-flto=thin --sysroot=/sysroot
          __0
      - name: Install aarch64 lld
        run: ./tools/install_prebuilt.js ld64.lld
        if: '!(matrix.skip) && (matrix.os == ''macos-13-xlarge'')'
      - name: Install rust-codesign
        run: |-
          ./tools/install_prebuilt.js rcodesign
          echo $GITHUB_WORKSPACE/third_party/prebuilt/mac >> $GITHUB_PATH
        if: '!(matrix.skip) && ((matrix.os == ''macos-13-xlarge'' || matrix.os == ''macos-12''))'
      - name: Log versions
        run: |-
          python --version
          rustc --version
          cargo --version
          which dpkg && dpkg -l
          if [[ "${{ matrix.job }}" == "lint" ]] || [[ "${{ matrix.job }}" == "test" ]]; then
            deno --version
          fi
          if [ "${{ matrix.job }}" == "bench" ]
          then
            node -v
            ./tools/install_prebuilt.js wrk hyperfine
          fi
        if: '!(matrix.skip)'
      - name: Cache Cargo home
        uses: actions/cache@v3
        with:
          path: |-
            ~/.cargo/registry/index
            ~/.cargo/registry/cache
          key: '69-cargo-home-${{ matrix.os }}-${{ hashFiles(''Cargo.lock'') }}'
          restore-keys: '69-cargo-home-${{ matrix.os }}'
        if: '!(matrix.skip)'
      - name: Restore cache build output (PR)
        uses: actions/cache/restore@v3
        if: '!(matrix.skip) && (github.ref != ''refs/heads/main'' && !startsWith(github.ref, ''refs/tags/''))'
        with:
          path: |-
            ./target
            !./target/*/gn_out
            !./target/*/*.zip
            !./target/*/*.tar.gz
          key: never_saved
          restore-keys: '69-cargo-target-${{ matrix.os }}-${{ matrix.profile }}-${{ matrix.job }}-'
      - name: Apply and update mtime cache
        if: '!(matrix.skip) && (!startsWith(github.ref, ''refs/tags/''))'
        uses: ./.github/mtime_cache
        with:
          cache-path: ./target
      - name: test_format.js
        if: '!(matrix.skip) && (matrix.job == ''lint'' && startsWith(matrix.os, ''ubuntu''))'
        run: deno run --unstable --allow-write --allow-read --allow-run --allow-net ./tools/format.js --check
      - name: Lint PR title
        if: '!(matrix.skip) && (matrix.job == ''lint'' && github.event_name == ''pull_request'' && startsWith(matrix.os, ''ubuntu''))'
        env:
          PR_TITLE: '${{ github.event.pull_request.title }}'
        run: deno run ./tools/verify_pr_title.js "$PR_TITLE"
      - name: lint.js
        if: '!(matrix.skip) && (matrix.job == ''lint'')'
        run: deno run --unstable --allow-write --allow-read --allow-run --allow-net ./tools/lint.js
      - name: node_compat/setup.ts --check
        if: '!(matrix.skip) && (matrix.job == ''lint'' && startsWith(matrix.os, ''ubuntu''))'
        run: deno run --allow-write --allow-read --allow-run=git ./tools/node_compat/setup.ts --check
      - name: Build debug
        if: '!(matrix.skip) && (matrix.job == ''test'' && matrix.profile == ''debug'')'
        run: |-
          df -h
          cargo build --locked --all-targets
          df -h
        env:
          CARGO_PROFILE_DEV_DEBUG: 0
      - name: Build release
        if: |-
          !(matrix.skip) && ((matrix.job == 'test' || matrix.job == 'bench') &&
          matrix.profile == 'release' && (matrix.use_sysroot ||
          github.repository == 'denoland/deno'))
        run: |-
          df -h
          cargo build --release --locked --all-targets
          df -h
      - name: Upload PR artifact (linux)
        if: |-
          !(matrix.skip) && (matrix.job == 'test' &&
          matrix.profile == 'release' && (matrix.use_sysroot ||
          (github.repository == 'denoland/deno' &&
          (github.ref == 'refs/heads/main' ||
          startsWith(github.ref, 'refs/tags/')))))
        uses: actions/upload-artifact@v3
        with:
          name: 'deno-${{ github.event.number }}'
          path: target/release/deno
      - name: Pre-release (linux)
        if: |-
          !(matrix.skip) && (startsWith(matrix.os, 'ubuntu') &&
          matrix.job == 'test' &&
          matrix.profile == 'release' &&
          github.repository == 'denoland/deno')
        run: |-
          cd target/release
          zip -r deno-x86_64-unknown-linux-gnu.zip deno
          ./deno types > lib.deno.d.ts
      - name: Pre-release (mac intel)
        if: |-
          !(matrix.skip) && (matrix.os == 'macos-12' &&
          matrix.job == 'test' &&
          matrix.profile == 'release' &&
          github.repository == 'denoland/deno')
        env:
          APPLE_CODESIGN_KEY: '${{ secrets.APPLE_CODESIGN_KEY }}'
          APPLE_CODESIGN_PASSWORD: '${{ secrets.APPLE_CODESIGN_PASSWORD }}'
        run: |-
          echo "Key is $(echo $APPLE_CODESIGN_KEY | base64 -d | wc -c) bytes"
          rcodesign sign target/release/deno --code-signature-flags=runtime --p12-password="$APPLE_CODESIGN_PASSWORD" --p12-file=<(echo $APPLE_CODESIGN_KEY | base64 -d) --entitlements-xml-file=cli/entitlements.plist
          cd target/release
          zip -r deno-x86_64-apple-darwin.zip deno
      - name: Pre-release (mac aarch64)
        if: |-
          !(matrix.skip) && (matrix.os == 'macos-13-xlarge' &&
          matrix.job == 'test' &&
          matrix.profile == 'release' &&
          github.repository == 'denoland/deno')
        env:
          APPLE_CODESIGN_KEY: '${{ secrets.APPLE_CODESIGN_KEY }}'
          APPLE_CODESIGN_PASSWORD: '${{ secrets.APPLE_CODESIGN_PASSWORD }}'
        run: |-
          echo "Key is $(echo $APPLE_CODESIGN_KEY | base64 -d | wc -c) bytes"
          rcodesign sign target/release/deno --code-signature-flags=runtime --p12-password="$APPLE_CODESIGN_PASSWORD" --p12-file=<(echo $APPLE_CODESIGN_KEY | base64 -d) --entitlements-xml-file=cli/entitlements.plist
          cd target/release
          zip -r deno-aarch64-apple-darwin.zip deno
      - name: Pre-release (windows)
        if: |-
          !(matrix.skip) && (startsWith(matrix.os, 'windows') &&
          matrix.job == 'test' &&
          matrix.profile == 'release' &&
          github.repository == 'denoland/deno')
        shell: pwsh
        run: Compress-Archive -CompressionLevel Optimal -Force -Path target/release/deno.exe -DestinationPath target/release/deno-x86_64-pc-windows-msvc.zip
      - name: Upload canary to dl.deno.land (unix)
        if: |-
          !(matrix.skip) && (runner.os != 'Windows' &&
          matrix.job == 'test' &&
          matrix.profile == 'release' &&
          github.repository == 'denoland/deno' &&
          github.ref == 'refs/heads/main')
        run: 'gsutil -h "Cache-Control: public, max-age=3600" cp ./target/release/*.zip gs://dl.deno.land/canary/$(git rev-parse HEAD)/'
      - name: Upload canary to dl.deno.land (windows)
        if: |-
          !(matrix.skip) && (runner.os == 'Windows' &&
          matrix.job == 'test' &&
          matrix.profile == 'release' &&
          github.repository == 'denoland/deno' &&
          github.ref == 'refs/heads/main')
        env:
          CLOUDSDK_PYTHON: '${{env.pythonLocation}}\python.exe'
        run: 'gsutil -h "Cache-Control: public, max-age=3600" cp ./target/release/*.zip gs://dl.deno.land/canary/$(git rev-parse HEAD)/'
      - name: Autobahn testsuite
        if: |-
          !(matrix.skip) && (matrix.job == 'test' && matrix.profile == 'release' &&
          !startsWith(github.ref, 'refs/tags/') && startsWith(matrix.os, 'ubuntu'))
        run: target/release/deno run -A --unstable ext/websocket/autobahn/fuzzingclient.js
      - name: Test debug
        if: |-
          !(matrix.skip) && (matrix.job == 'test' && matrix.profile == 'debug' &&
          !startsWith(github.ref, 'refs/tags/') && startsWith(matrix.os, 'ubuntu'))
        run: cargo test --locked
        env:
          CARGO_PROFILE_DEV_DEBUG: 0
      - name: Test debug (fast)
        if: |-
          !(matrix.skip) && (matrix.job == 'test' && matrix.profile == 'debug' &&
          (startsWith(github.ref, 'refs/tags/') || !startsWith(matrix.os, 'ubuntu')))
        run: |-
          cargo test --locked --lib
          cargo test --locked --test '*'
        env:
          CARGO_PROFILE_DEV_DEBUG: 0
      - name: Test release
        if: |-
          !(matrix.skip) && (matrix.job == 'test' && matrix.profile == 'release' &&
          (matrix.use_sysroot || (
          github.repository == 'denoland/deno' &&
          !startsWith(github.ref, 'refs/tags/'))))
        run: cargo test --release --locked
      - name: Check deno binary
        if: '!(matrix.skip) && (matrix.profile == ''release'' && startsWith(github.ref, ''refs/tags/''))'
        run: target/release/deno eval "console.log(1+2)" | grep 3
        env:
          NO_COLOR: 1
      - name: Check deno binary (in sysroot)
        if: '!(matrix.skip) && (matrix.profile == ''release'' && matrix.use_sysroot)'
        run: sudo chroot /sysroot "$(pwd)/target/release/deno" --version
      - name: Configure hosts file for WPT
        if: '!(matrix.skip) && (matrix.wpt)'
        run: ./wpt make-hosts-file | sudo tee -a /etc/hosts
        working-directory: test_util/wpt/
      - name: Run web platform tests (debug)
        if: '!(matrix.skip) && (matrix.wpt && matrix.profile == ''debug'')'
        env:
          DENO_BIN: ./target/debug/deno
        run: |-
          deno run --allow-env --allow-net --allow-read --allow-run \
                  --allow-write --unstable                         \
                  --lock=tools/deno.lock.json                      \
                  ./tools/wpt.ts setup
          deno run --allow-env --allow-net --allow-read --allow-run \
                   --allow-write --unstable                         \
                   --lock=tools/deno.lock.json              \
                   ./tools/wpt.ts run --quiet --binary="$DENO_BIN"
      - name: Run web platform tests (release)
        if: '!(matrix.skip) && (matrix.wpt && matrix.profile == ''release'')'
        env:
          DENO_BIN: ./target/release/deno
        run: |-
          deno run --allow-env --allow-net --allow-read --allow-run \
                   --allow-write --unstable                         \
                   --lock=tools/deno.lock.json                      \
                   ./tools/wpt.ts setup
          deno run --allow-env --allow-net --allow-read --allow-run \
                   --allow-write --unstable                         \
                   --lock=tools/deno.lock.json                      \
                   ./tools/wpt.ts run --quiet --release             \
                                      --binary="$DENO_BIN"          \
                                      --json=wpt.json               \
                                      --wptreport=wptreport.json
      - name: Upload wpt results to dl.deno.land
        continue-on-error: true
        if: |-
          !(matrix.skip) && (matrix.wpt &&
          runner.os == 'Linux' &&
          matrix.profile == 'release' &&
          github.repository == 'denoland/deno' &&
          github.ref == 'refs/heads/main' && !startsWith(github.ref, 'refs/tags/'))
        run: |-
          gzip ./wptreport.json
          gsutil -h "Cache-Control: public, max-age=3600" cp ./wpt.json gs://dl.deno.land/wpt/$(git rev-parse HEAD).json
          gsutil -h "Cache-Control: public, max-age=3600" cp ./wptreport.json.gz gs://dl.deno.land/wpt/$(git rev-parse HEAD)-wptreport.json.gz
          echo $(git rev-parse HEAD) > wpt-latest.txt
          gsutil -h "Cache-Control: no-cache" cp wpt-latest.txt gs://dl.deno.land/wpt-latest.txt
      - name: Upload wpt results to wpt.fyi
        continue-on-error: true
        if: |-
          !(matrix.skip) && (matrix.wpt &&
          runner.os == 'Linux' &&
          matrix.profile == 'release' &&
          github.repository == 'denoland/deno' &&
          github.ref == 'refs/heads/main' && !startsWith(github.ref, 'refs/tags/'))
        env:
          WPT_FYI_USER: deno
          WPT_FYI_PW: '${{ secrets.WPT_FYI_PW }}'
          GITHUB_TOKEN: '${{ secrets.DENOBOT_PAT }}'
        run: |-
          ./target/release/deno run --allow-all --lock=tools/deno.lock.json \
              ./tools/upload_wptfyi.js $(git rev-parse HEAD) --ghstatus
      - name: Run benchmarks
        if: '!(matrix.skip) && (matrix.job == ''bench'' && !startsWith(github.ref, ''refs/tags/''))'
        run: cargo bench --locked
      - name: Post Benchmarks
        if: |-
          !(matrix.skip) && (matrix.job == 'bench' &&
          github.repository == 'denoland/deno' &&
          github.ref == 'refs/heads/main' && !startsWith(github.ref, 'refs/tags/'))
        env:
          DENOBOT_PAT: '${{ secrets.DENOBOT_PAT }}'
        run: |-
          git clone --depth 1 --branch gh-pages                             \
              https://${DENOBOT_PAT}@github.com/denoland/benchmark_data.git \
              gh-pages
          ./target/release/deno run --allow-all --unstable \
              ./tools/build_benchmark_jsons.js --release
          cd gh-pages
          git config user.email "propelml@gmail.com"
          git config user.name "denobot"
          git add .
          git commit --message "Update benchmarks"
          git push origin gh-pages
      - name: Build product size info
        if: '!(matrix.skip) && (matrix.job != ''lint'' && matrix.profile != ''debug'' && github.repository == ''denoland/deno'' && (github.ref == ''refs/heads/main'' || startsWith(github.ref, ''refs/tags/'')))'
        run: |-
          du -hd1 "./target/${{ matrix.profile }}"
          du -ha  "./target/${{ matrix.profile }}/deno"
      - name: Worker info
        if: '!(matrix.skip) && (matrix.job == ''bench'')'
        run: |-
          cat /proc/cpuinfo
          cat /proc/meminfo
      - name: Upload release to dl.deno.land (unix)
        if: |-
          !(matrix.skip) && (runner.os != 'Windows' &&
          matrix.job == 'test' &&
          matrix.profile == 'release' &&
          github.repository == 'denoland/deno' &&
          startsWith(github.ref, 'refs/tags/'))
        run: 'gsutil -h "Cache-Control: public, max-age=3600" cp ./target/release/*.zip gs://dl.deno.land/release/${GITHUB_REF#refs/*/}/'
      - name: Upload release to dl.deno.land (windows)
        if: |-
          !(matrix.skip) && (runner.os == 'Windows' &&
          matrix.job == 'test' &&
          matrix.profile == 'release' &&
          github.repository == 'denoland/deno' &&
          startsWith(github.ref, 'refs/tags/'))
        env:
          CLOUDSDK_PYTHON: '${{env.pythonLocation}}\python.exe'
        run: 'gsutil -h "Cache-Control: public, max-age=3600" cp ./target/release/*.zip gs://dl.deno.land/release/${GITHUB_REF#refs/*/}/'
      - name: Create release notes
        if: |-
          !(matrix.skip) && (matrix.job == 'test' &&
          matrix.profile == 'release' &&
          github.repository == 'denoland/deno' &&
          startsWith(github.ref, 'refs/tags/'))
        run: |-
          export PATH=$PATH:$(pwd)/target/release
          ./tools/release/05_create_release_notes.ts
      - name: Upload release to GitHub
        uses: softprops/action-gh-release@v0.1.15
        if: |-
          !(matrix.skip) && (matrix.job == 'test' &&
          matrix.profile == 'release' &&
          github.repository == 'denoland/deno' &&
          startsWith(github.ref, 'refs/tags/'))
        env:
          GITHUB_TOKEN: '${{ secrets.GITHUB_TOKEN }}'
        with:
          files: |-
            target/release/deno-x86_64-pc-windows-msvc.zip
            target/release/deno-x86_64-unknown-linux-gnu.zip
            target/release/deno-x86_64-apple-darwin.zip
            target/release/deno-aarch64-apple-darwin.zip
            target/release/deno_src.tar.gz
            target/release/lib.deno.d.ts
          body_path: target/release/release-notes.md
          draft: true
      - name: Save cache build output (main)
        uses: actions/cache/save@v3
        if: '!(matrix.skip) && ((matrix.job == ''test'' || matrix.job == ''lint'') && github.ref == ''refs/heads/main'')'
        with:
          path: |-
            ./target
            !./target/*/gn_out
            !./target/*/*.zip
            !./target/*/*.tar.gz
          key: '69-cargo-target-${{ matrix.os }}-${{ matrix.profile }}-${{ matrix.job }}-${{ github.sha }}'
  publish-canary:
    name: publish canary
    runs-on: ubuntu-22.04
    needs:
      - build
    if: github.repository == 'denoland/deno' && github.ref == 'refs/heads/main'
    steps:
      - name: Authenticate with Google Cloud
        uses: google-github-actions/auth@v1
        with:
          project_id: denoland
          credentials_json: '${{ secrets.GCP_SA_KEY }}'
          export_environment_variables: true
          create_credentials_file: true
      - name: Setup gcloud
        uses: google-github-actions/setup-gcloud@v1
        with:
          project_id: denoland
      - name: Upload canary version file to dl.deno.land
        run: |-
          echo ${{ github.sha }} > canary-latest.txt
          gsutil -h "Cache-Control: no-cache" cp canary-latest.txt gs://dl.deno.land/canary-latest.txt

```


# docker and dockerfile

docker container stop
docker container kill
docker container remove

```dockerfile

FROM alpine
CMD ["echo", "Hello World!"]

WORKDIR /usr/src

RUN apt update && apt install -y python3 python3-pip

RUN useradd --create-home appuser
USER appuser

COPY app.py .

ENTRYPOINT ["python3", "-m", "http.server"]
CMD ["8000"]

LABEL maintainer="tannal"
LABEL version = "1.0"
LABEL description = "more garbage code"

ENV API_KEY=hi_mom

EXPOSE 8000

HEALTHCHECK --interval=30s --timeout=10s \
  CMD curl -f http://localhost:6969/health || exit 1

VOLUME /db/data

docker build . -t awesome

docker build -f Dockerfile -t alpine:helloworld

```


```dockerfile

FROM alpine
CMD ["echo", "Hello World!"]

docker build -f Dockerfile -t alpine:helloworld
```

# frp systemd service


```bash

wget https://github.com/fatedier/frp/releases/download/v0.53.2/frp_0.53.2_linux_arm64.tar.gz

tar xvf frp_0.53.2_linux_arm64.tar.gz

wget https://github.com/fatedier/frp/releases/download/v0.53.2/frp_0.53.2_linux_amd64.tar.gz

sudo vim /etc/systemd/system/frps.service

config https://github.com/fatedier/frp/blob/1e8806d26b6c1ca5ee683deb38f64f89fe60c1fe/conf/frps_full_example.toml#L121

[Unit]
# 服务名称，可自定义
Description = frp server
After = network.target syslog.target
Wants = network.target

[Service]
Type = simple
# 启动frps的命令，需修改为您的frps的安装路径
ExecStart = /home/ubuntu/tannalwork/projects/frp_0.53.2_linux_amd64/frps -c /home/ubuntu/tannalwork/projects/frp_0.53.2_linux_amd64/frps.toml
Restart=always

[Install]
WantedBy = multi-user.target

# 启动frp
sudo systemctl start frps
# 停止frp
sudo systemctl stop frps
# 重启frp
sudo systemctl restart frps
# 查看frp状态
sudo systemctl status frps


sudo systemctl enable frps


sudo vim /etc/systemd/system/frpc.service
[Unit]
# 服务名称，可自定义
Description = frpc
After = network.target syslog.target
After=network-online.target
Wants=network-online.target systemd-networkd-wait-online.service

[Service]
Type = simple
# 启动frps的命令，需修改为您的frps的安装路径
ExecStart = /home/tannal/tannalwork/projects/frp_0.53.2_linux_arm64/frpc -c /home/tannal/tannalwork/projects/frp_0.53.2_linux_arm64/frpc.toml
Restart=always

[Install]
WantedBy = multi-user.target

sudo systemctl enable frpc

journalctl -u frpc.service


tar xvf frp_0.53.2_linux_amd64.tar.gz

./frps -c frps.toml


@tod
o clash systemctl

```


# symbol link lld

```bash

sudo apt install lld
sudo rm /usr/bin/ld

sudo ln -s /usr/bin/lld /usr/bin/ld
sudo ln -s /usr/bin/ld.lld /usr/bin/ld
sudo ln -sfn /usr/bin/lld /usr/bin/ld
sudo ln -s x86 /usr/bin/ld

sudo ln -sfn x86_64-linux-gnu-ld /usr/bin/ld
sudo ln -sfn aarch64-linux-gnu-ld /usr/bin/ld

sudo ln -sfn x86_64-linux-gnu-ld /usr/bin/ld

strace -e execve lld
strace -e execve ld

```

# ssh authorized keys

```bash

Ed25519 algorithm

rsa algorithm

vim ~/.ssh/authorized_keys

ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIDeryWc8zLoFzIIG1CaTRPD/WEY3ca6mqiLTpYSdPcYq tannal@ubuntu

ssh-keygen -t ed25519

```

# yolo v8

```bash

virtualenv yxl python=python3.8
virtualenv yxl --python=python3.8

Set-ExecutionPolicy Unrestricted -Force

set-executionpolicy remotesigned

Activate yxl/bin/activate

yxl/Scripts/activate

../yxl/Scripts/activate

pip freeze


pip install torch==1.2.0


git clone https://github.com/ultralytics/ultralytics.git


pip install .

nvidia-smi
CUDA Version: 12.2

pip install torch==2.0.1 torchvision==0.15+cu111 torchaudio==2.0.2

PyTorch	TorchAudio	Python
2.0.1	2.0.2	>=3.8 , <=3.11
2.0.0	2.0.1	>=3.8 , <=3.11
1.13.1	0.13.1	>=3.7 , <=3.10
1.13.0	0.13.0	>=3.7 , <=3.10

pip install ultralytics

```

# raylib starter

```bash
# CMakeLists.txt

cmake_minimum_required(VERSION 3.0.0)
project(ray VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

file(GLOB EXAMPLE_SOURCES "*.cc")
find_package(raylib CONFIG REQUIRED)


foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    target_link_libraries(${EXAMPLE_NAME} PRIVATE raylib)
endforeach()

# main.cc
/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

```

# express server nodejs

corepack enable

sudo ./funcgraph -p 47889 tcp_update_skb_after_send -m 2


pnpm init -y
pnpm i express


const express = require('express')
const app = express()
const port = 3000

app.get('/', (req, res) => {
    console.log('Hello')
    res.send('Hello World!')
})

app.listen(port, () => {

    console.log(`Example app listening on port ${port}`)
})

if (process.pid) {
    console.log('This process is your pid ' + process.pid);
}


# vjudge in nodejs

```js
#!/home/tannal/.nvm/versions/node/v20.10.0/bin/node

const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
});

const inspector = require('inspector');
const debug = inspector.url() !== undefined

console.debug = (...args) => {
  if (debug) {
    console.log(...args)
  }
}

function solve(/** @type {number[]} */ balloons) {
  console.debug(balloons)
  let count = 0

  let current = []

  for(let i = 0; i < balloons.length; i++) {
    if(current.some(v => v === balloons[i])) {  
      let idx = current.findIndex(v => v === balloons[i])
      current[idx]--
    }else {   
      count++
      current.push(balloons[i] - 1)
    }
  }
  console.log(count)
}

const processInput = (lines) => {
    let n = +lines.shift()
    let balloons = lines.shift()
    solve(balloons.split(' ').map(v => +v))
};

const readInputLines = async () => {
  const lines = [];
  for await (const line of rl) {
    lines.push(line);
  }
  return lines;
};

readInputLines().then(lines => {
  processInput(lines);
});

```


# python plt 

```py

// us_gdp.csv
// https://datahub.io/core/gdp-us#resource-yea  r
date,level-current,level-chained,change-current,change-chained
1930,92.2,966.7,-16.0,-6.4
1931,77.4,904.8,-23.1,-12.9
1932,59.5,788.2,-4.0,-1.3
1933,57.2,778.3,16.9,10.8
1934,66.8,862.2,11.1,8.9
1935,74.3,939.0,14.3,12.9
1936,84.9,1060.5,9.6,5.1
1937,93.0,1114.6,-6.1,-3.3
1938,87.4,1077.7,7.0,8.0
1939,93.5,1163.6,10.1,8.8
1940,102.9,1266.1,25.7,17.7
1941,129.4,1490.3,28.3,18.9
1942,166.0,1771.8,22.4,17.0
1943,203.1,2073.7,10.5,8.0
1944,224.6,2239.4,1.6,-1.0
1945,228.2,2217.8,-0.2,-11.6
1946,227.8,1960.9,9.7,-1.1
1947,249.9,1939.4,9.9,4.1
1948,274.8,2020.0,-0.7,-0.5
1949,272.8,2008.9,10.0,8.7
1950,300.2,2184.0,15.7,8.1
1951,347.3,2360.0,5.9,4.1
1952,367.7,2456.1,6.0,4.7
1953,389.7,2571.4,0.4,-0.6
1954,391.1,2556.9,9.0,7.1
1955,426.2,2739.0,5.6,2.1
1956,450.1,2797.4,5.5,2.1
1957,474.9,2856.3,1.5,-0.7
1958,482.0,2835.3,8.4,6.9
1959,522.5,3031.0,4.0,2.6
1960,543.3,3108.7,3.7,2.6
1961,563.3,3188.1,7.4,6.1
1962,605.1,3383.1,5.5,4.4
1963,638.6,3530.4,7.4,5.8
1964,685.8,3734.0,8.4,6.5
1965,743.7,3976.7,9.6,6.6
1966,815.0,4238.9,5.7,2.7
1967,861.7,4355.2,9.4,4.9
1968,942.5,4569.0,8.2,3.1
1969,1019.9,4712.5,5.5,0.2
1970,1075.9,4722.0,8.5,3.3
1971,1167.8,4877.6,9.8,5.2
1972,1282.4,5134.3,11.4,5.6
1973,1428.5,5424.1,8.4,-0.5
1974,1548.8,5396.0,9.0,-0.2
1975,1688.9,5385.4,11.2,5.4
1976,1877.6,5675.4,11.1,4.6
1977,2086.0,5937.0,13.0,5.6
1978,2356.6,6267.2,11.7,3.2
1979,2632.1,6466.2,8.8,-0.2
1980,2862.5,6450.4,12.2,2.6
1981,3211.0,6617.7,4.2,-1.9
1982,3345.0,6491.3,8.8,4.6
1983,3638.1,6792.0,11.1,7.3
1984,4040.7,7285.0,7.6,4.2
1985,4346.7,7593.8,5.6,3.5
1986,4590.2,7860.5,6.1,3.5
1987,4870.2,8132.6,7.9,4.2
1988,5252.6,8474.5,7.7,3.7
1989,5657.7,8786.4,5.7,1.9
1990,5979.6,8955.0,3.3,-0.1
1991,6174.0,8948.4,5.9,3.6
1992,6539.3,9266.6,5.2,2.7
1993,6878.7,9521.0,6.3,4.0
1994,7308.8,9905.4,4.9,2.7
1995,7664.1,10174.8,5.7,3.8
1996,8100.2,10561.0,6.3,4.5
1997,8608.5,11034.9,5.6,4.5
1998,9089.2,11525.9,6.3,4.7
1999,9660.6,12065.9,6.5,4.1
2000,10284.8,12559.7,3.3,1.0
2001,10621.8,12682.2,3.3,1.8
2002,10977.5,12908.8,4.9,2.8
2003,11510.7,13271.1,6.6,3.8
2004,12274.9,13773.5,6.7,3.3
2005,13093.7,14234.2,5.8,2.7
2006,13855.9,14613.8,4.5,1.8
2007,14477.6,14873.7,1.7,-0.3
2008,14718.6,14830.4,-2.0,-2.8
2009,14418.7,14418.7,3.8,2.5
2010,14964.4,14783.8,3.7,1.6
2011,15517.9,15020.6,4.1,2.2
2012,16155.3,15354.6,3.3,1.7
2013,16691.5,15612.2,4.4,2.6
2014,17427.6,16013.3,4.0,2.9
2015,18120.7,16471.5,2.8,1.5



// us_gdp.py
import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
data = pd.read_csv('us_gdp.csv')

# Extract the required columns
years = data['date']
current_levels = data['level-current']
chained_levels = data['level-chained']
change_current = data['change-current']
change_chained = data['change-chained']

# Create a line plot for current and chained levels
plt.plot(years, current_levels, label='Current Levels')
plt.plot(years, chained_levels, label='Chained Levels')

plt.xlabel('Year')
plt.ylabel('Level')
plt.title('Current and Chained Levels Over Time')
plt.legend()

plt.show()

# Create a bar plot for changes in current and chained levels
plt.bar(years, change_current, label='Change Current')
plt.bar(years, change_chained, label='Change Chained')

plt.xlabel('Year')
plt.ylabel('Change')
plt.title('Changes in Current and Chained Levels Over Time')
plt.legend()

plt.show()

```


# winget setup in powershell

```powershell

$progressPreference = 'silentlyContinue'
Write-Information "Downloading WinGet and its dependencies..."
Invoke-WebRequest -Uri https://aka.ms/getwinget -OutFile Microsoft.DesktopAppInstaller_8wekyb3d8bbwe.msixbundle
Invoke-WebRequest -Uri https://aka.ms/Microsoft.VCLibs.x64.14.00.Desktop.appx -OutFile Microsoft.VCLibs.x64.14.00.Desktop.appx
Invoke-WebRequest -Uri https://github.com/microsoft/microsoft-ui-xaml/releases/download/v2.7.3/Microsoft.UI.Xaml.2.7.x64.appx -OutFile Microsoft.UI.Xaml.2.7.x64.appx
Add-AppxPackage Microsoft.VCLibs.x64.14.00.Desktop.appx
Add-AppxPackage Microsoft.UI.Xaml.2.7.x64.appx
Add-AppxPackage Microsoft.DesktopAppInstaller_8wekyb3d8bbwe.msixbundle

```

# Libuv V8

```cpp
// main.cpp
#include <iostream>
#include <uv.h>
#include <v8.h>

void on_uv_walk(uv_handle_t* handle, void* arg) {
    if (!uv_is_closing(handle)) {
        uv_close(handle, nullptr);
    }
}

void on_uv_close(uv_handle_t* handle) {
    if (handle->data) {
        delete static_cast<v8::Isolate*>(handle->data);
        handle->data = nullptr;
    }
}

void on_uv_read(uv_stream_t* stream, ssize_t nread, const uv_buf_t* buf) {
    if (nread > 0) {
        std::cout << "Received data: " << std::string(buf->base, nread) << std::endl;
    }
    if (nread < 0) {
        if (nread != UV_EOF) {
            std::cerr << "Read error: " << uv_strerror(nread) << std::endl;
        }
        uv_close(reinterpret_cast<uv_handle_t*>(stream), nullptr);
    }
    delete[] buf->base;
}

void on_uv_connection(uv_stream_t* server, int status) {
    if (status < 0) {
        std::cerr << "Connection error: " << uv_strerror(status) << std::endl;
        return;
    }

    uv_tcp_t* client = new uv_tcp_t;
    uv_tcp_init(uv_default_loop(), client);

    if (uv_accept(server, reinterpret_cast<uv_stream_t*>(client)) == 0) {
        uv_read_start(reinterpret_cast<uv_stream_t*>(client),
                      [](uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf) {
                          *buf = uv_buf_init(new char[suggested_size], suggested_size);
                      },
                      on_uv_read);
    } else {
        uv_close(reinterpret_cast<uv_handle_t*>(client), nullptr);
        delete client;
    }
}

int main() {
    v8::V8::InitializeICUDefaultLocation("");
    v8::V8::InitializeExternalStartupData("");
    v8::V8::InitializePlatform(v8::platform::CreateDefaultPlatform());
    v8::V8::Initialize();

    v8::Isolate::CreateParams create_params;
    v8::Isolate* isolate = v8::Isolate::New(create_params);

    uv_tcp_t server;
    uv_tcp_init(uv_default_loop(), &server);

    sockaddr_in bind_addr;
    uv_ip4_addr("0.0.0.0", 3000, &bind_addr);
    uv_tcp_bind(&server, reinterpret_cast<const sockaddr*>(&bind_addr), 0);

    int res = uv_listen(reinterpret_cast<uv_stream_t*>(&server), 128, on_uv_connection);
    if (res < 0) {
        std::cerr << "Listen error: " << uv_strerror(res) << std::endl;
        return 1;
    }

    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    uv_walk(uv_default_loop(), on_uv_walk, nullptr);
    uv_run(uv_default_loop(), UV_RUN_DEFAULT);
    uv_loop_close(uv_default_loop());

    isolate->Dispose();
    v8::V8::Dispose();
    v8::V8::ShutdownPlatform();

    return 0;
}

```
# TypeScript setup

```bash
npm init -y
npm install ts-node typescript @types/node
npx tsc --init
```

tsconfig.json

```json
"strict": true,
"noImplicitAny": true,
"strictNullChecks": true,
"strictFunctionTypes": true,
"strictBindCallApply": true,
"strictPropertyInitialization": true,
"noImplicitThis": true,
"useUnknownInCatchVariables": true,
"alwaysStrict": true,
"noUnusedLocals": true,
"noUnusedParameters": true,
"exactOptionalPropertyTypes": true,
"noImplicitReturns": true,
"noFallthroughCasesInSwitch": true,
"noUncheckedIndexedAccess": true,
"noImplicitOverride": true,
"noPropertyAccessFromIndexSignature": true,
```

# cmake project starter

```bash

cmake_minimum_required(VERSION 2.8.9)
project (myproject)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "*.cc")
file(GLOB LIBRARIES "lib/*.a")
message("LIBRARIES = ${LIBRARIES}")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(myproject ${SOURCES})
target_link_libraries(myproject ${LIBRARIES})  

cmake -S . -B build
cmake --build build

ln -s build/compile_commands.json compile_commands.json 

```

# systemd service

sudo vim /etc/systemd/system/docs.service

[Unit]
# 服务名称，可自定义
Description = docs

[Service]
Type = simple
WorkingDirectory=/home/tannal/tannalwork/projects/yjs-demos/
ExecStart = /bin/bash -c 'PATH=/home/tannal/.nvm/versions/node/v20.11.0/bin/:$PATH pnpm start'
Restart=always

[Install]
WantedBy = multi-user.target

# create n thread print 1..n in golang

```go

package main

import (
	"fmt"
	"sync"
	"time"
)

func wait(seconds int, wg *sync.WaitGroup) {
	defer wg.Done()

	time.Sleep(time.Duration(seconds) * time.Second)
	fmt.Println("Slept ", seconds, " seconds ..")
}

func main() {
	var wg sync.WaitGroup

	for i := 0; i <= 5; i++ {
		wg.Add(1)
		go wait(i, &wg)
	}
	wg.Wait()
}

```



# hello world linux module

make

sudo make load

sudo make unload

sudo dmesg

```c
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int hello_init(void)
{
    printk(KERN_ALERT "Hello, world\n");
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
```
```Makefile

obj-m += hello.o

.PHONY: build clean load unload

build:
	make -C /lib/modules/$(shell uname -r)/build modules M=$(shell pwd)

clean:
	make -C /lib/modules/$(shell uname -r)/build clean M=$(shell pwd)

load:
	sudo insmod hello.ko
unload:
	sudo rmmod hello
```

# cmake print variable

include(CMakePrintHelpers)

cmake_print_variables(LLD_DIR)


# git config for git send mail with gmail

```
[user]
    name = Meng Tan
    email = tannal2409@gmail.com
[sendemail]
    smtpServer = smtp.gmail.com
    smtpServerPort = 587
    smtpEncryption = tls
    smtpUser = tannal2409@gmail.com
    # (Optional: we'll leave this commented out and use a different way)
    # smtpPass = PASSWORD
[credential]
    helper = store
```

# configuration for wifi auto connect when boot raspi

sudo vim /etc/network/interfaces

auto wlan0
iface wlan0 inet static
address 192.168.43.246
netmask 255.255.255.0
gateway 192.168.43.1
wireless-essid 小米手机
wireless-key 9711eeb1f089