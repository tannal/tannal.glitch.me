
https://mastodon.social/@ltratt

https://mastodon.social/@mreinhold

https://mastodon.social/@b0rk@jvns.ca

https://mastodon.gamedev.place/@Nical

```bash
git clone https://github.com/grishka/appkit.git
cd appkit
检出最新的标签版本(假设是 1.4.0):


./gradlew wrapper --gradle-version=8.4
./gradlew clean build
安装到本地 Maven 仓库:

./gradlew publishToMavenLocal
现在,在你的项目的 build.gradle 文件中,添加 mavenLocal() 到仓库列表:
gradle

repositories {
    mavenCentral()
    mavenLocal()
}
然后在你的模块的 build.gradle 中添加依赖:
gradle

dependencies {
    implementation 'me.grishka.appkit:appkit:1.4.0'
}


同步你的项目。
如果你遇到任何问题,可能需要检查:

确保你的 Gradle 版本与项目兼容。
检查 local.properties 文件中的 SDK 路径是否正确。
如果构建失败,查看错误信息并解决任何缺失的依赖。
```