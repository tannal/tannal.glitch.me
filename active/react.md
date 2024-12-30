
# React Native

yarn remove react-native-gesture-handler react-native-reanimated
yarn add react-native-gesture-handler@2.14.0 react-native-reanimated@3.6.1



> Task :shopify_react-native-skia:configureCMakeDebug[x86_64]
C/C++: -- ABI     : x86_64
C/C++: -- PREBUILT: /home/a17/tannalwork/projects/RippleDemo/node_modules/@shopify/react-native-skia/android/build/react-native-0*/jni
C/C++: -- BUILD   : /home/a17/tannalwork/projects/RippleDemo/node_modules/@shopify/react-native-skia/android/build
C/C++: -- LIBRN   :
C/C++: -- LOG     : /home/a17/Android/Sdk/ndk/26.1.10909125/toolchains/llvm/prebuilt/linux-x86_64/sysroot/usr/lib/x86_64-linux-android/24/liblog.so
C/C++: -- JSI     : ReactAndroid::jsi
C/C++: -- REACT   : ReactAndroid::reactnative
C/C++: -- FBJNI   : fbjni::fbjni
C/C++: -- REACTNATIVEJNI   :
C/C++: -- RUNTIMEEXECUTOR   :
C/C++: -- TURBO   :


# 清理 watchman
watchman watch-del-all

# 清理缓存
cd android && ./gradlew clean
cd ..
rm -rf node_modules
yarn cache clean
yarn install

# 重新运行
npx react-native run-android

com.facebook.react:react-native:0.72.x
├── com.facebook.yoga:yoga
├── com.facebook.yoga:proguard-annotations
├── com.facebook.fbjni:fbjni
├── com.facebook.soloader:soloader
├── com.facebook.infer.annotation:infer-annotation
└── androidx.appcompat:appcompat

// Hermes引擎
com.facebook.react:hermes-engine
└── com.facebook.react:hermes-android

// 或 JSC
org.webkit:android-jsc

com.squareup.okhttp3:okhttp:4.x
com.squareup.okio:okio

com.facebook.fresco:fresco
├── com.facebook.fresco:imagepipeline
├── com.facebook.fresco:middleware
├── com.facebook.fresco:ui-common
└── com.facebook.fresco:drawee

// 调试工具
com.facebook.flipper:flipper
com.facebook.flipper:flipper-network-plugin

// Fabric
com.facebook.react:react-native-fabric
com.facebook.react:react-native-turbomodule-core

// CodeGen
com.facebook.react:codegen

androidx.swiperefreshlayout:swiperefreshlayout
androidx.transition:transition
com.google.code.findbugs:jsr305
javax.inject:javax.inject

React Native Core
├── UIManager (主项目)
│   ├── 视图创建和更新
│   ├── 布局计算结果应用
│   └── 批量更新处理
│
├── Yoga (独立项目)
│   └── 布局计算
│
└── Bridge/JSI (主项目)
    └── 跨语言通信

# people

involves:sebmarkbage
involves:eps1lon
involves:gnoff
involves:rickhanlonii
involves:acdlite
involves:kassens
involves:hoxyq
involves:jackpope
involves:noahlemen
involves:yungsters
involves:gaearon
involves:Biki-das
involves:tyao1
involves:sophiebits
involves:josephsavona
involves:rubennorte
involves:motiz88
involves:sammy-SC
involves:mofeiZ
involves:cpojer
