# inbox

底层控制:
计划提供底层控制,允许通过html模块直接生成特定的HTML元素。
但不建议直接将这些添加到内容中,而是结合自定义类型,创建自定义元素,其show规则生成适当的HTML元素。
show规则可以根据输出格式(HTML/布局)进行条件判断。
语义标记:
对于没有直接等效HTML标签的Typst标记(如<article>, <aside>等),计划通过用户函数来控制HTML输出。
目标是为从语义内容生成任意HTML创建灵活的基础,而不是完全重用未修改的模板。
数学公式:
计划使用MathML来渲染数学公式,但可能需要提供图像作为备选。
对EPUB导出的支持仍在讨论中。
文件分割:
计划提供从单个typ文件生成单页面或多页面输出的完全控制。
默认行为还未确定。
交叉引用:
计划保留跨HTML页面的交叉引用功能。
安全性:
对于直接生成HTML/JavaScript的安全性有所顾虑。
考虑限制可能的HTML标签,或者阻止包中的JavaScript导出。
可能使用像ammonia这样的HTML清理库。
实现计划:
目前仍在修复和改进布局引擎。
之后将开始HTML导出的实现工作。
数学渲染:
数学渲染是计划的一部分,但具体优先级和实现方式(自建还是基于现有库)还在讨论中。

git remote add remote "Continuous integration"
gh repo set-default 
gh workflow run "Continuous integration" --ref ci

cargo test -p typst-tests --test tests text-spacing

selector

.\target\debug\typst.exe query .\test.typ heading
.\target\debug\typst.exe watch .\test.typ

Frame is a collection of frameItem
Shape MathFrameItem

Shape is Geometry plus fill and stroke



Martin Haug
Sits down and gets things done.

Laurenz Mädje
Thinks long and comes up with stuff.


# setup

git clone https://github.com/typst/typst.git

cargo build

# awesome typst


# people

involves:laurmaedje
involves:leedehai
involves:dherse
involves:frozolotl
involves:pgBiel
involves:mDLC01
involves:bluebear94
involves:reknih
involves:damaxwell
involves:EpicEricEE
involves:tingerrr
involves:Andrew15-5
involves:Enter-tainer
involves:peng1999
involves:LaurenzV
involves:Myriad-Dreamin
involves:LuxxxLucy
involves:Beiri22
involves:Jollywatt
involves:sitandr
involves:mattfbacon
involves:elegaanz
involves:figsoda
involves:DVDTSB
involves:istudyatuni
involves:jcbhmr
involves:jimvdl
involves:rikhuijzer
involves:antonWetzel
involves:Heinenen
involves:xkevio
involves:Mafii
involves:drupol
involves:lolstork
involves:raphCode
involves:A-Walrus
involves:lynn
involves:T0mstone
involves:KillTheMule
involves:danieleades
involves:cmoog
involves:SekoiaTree
involves:SUPERCILEX
involves:StrangeGirlMurph
involves:SimonRask
involves:freundTech
involves:HydroH
involves:pineapplehunter
involves:kg583
involves:s-cerevisiae
involves:YDX-2147483647
involves:mtoohey31
involves:epbuennig
involves:xalbd
involves:lucifer1004
involves:adriandelgado
involves:azerupi
involves:k-84mo10
involves:sudormrfbin
involves:TheJosefOlsson
involves:t-rapp
involves:Jocs
involves:sandalbanditten
involves:astrale-sharp
involves:rezzubs
involves:lihe07
involves:samueltardieu
involves:jbirnick
involves:MyrtleTurtle22
involves:fritzrehde
involves:muzimuzhi
involves:WeetHet
involves:3w36zj6
involves:toddlerer
involves:silvergasp
involves:Zheoni
involves:7sDream
involves:neunenak
involves:Luis-Licea
involves:jassler
involves:owiecc
involves:AlistairKeiller
involves:rpitasky
involves:naim94a
involves:johannes-wolf
involves:dccsillag
