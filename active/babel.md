
```ts

export interface Program extends NodeBase {
  type: "Program";
  sourceType: SourceType;
  body: Array<Statement | ModuleDeclaration>; // TODO: $ReadOnlyArray,
  directives: Directive[]; // TODO: Not in spec,
  interpreter: InterpreterDirective | null;
}

export interface NodeBase {
  start: number;
  end: number;
  loc: SourceLocation;
  range?: [number, number];
  leadingComments?: Array<Comment>;
  trailingComments?: Array<Comment>;
  innerComments?: Array<Comment>;
  extra?: {
    [key: string]: any;
  };
}

export interface File extends NodeBase, ParserOutput {
  type: "File";
  program: Program;
}


```

https://astexplorer.net/




```bash

git clone https://github.com/babel/babel



```


# people

author:nicolo-ribaudo
author:liuxingbaoyu
author:JLHwung
author:SuperSodaSea
author:fisker
author:Andarist
author:overlookmotel
author:magic-akari
author:danezauthor: