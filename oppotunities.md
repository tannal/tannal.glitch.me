
# KDE

https://community.kde.org/SoK/Ideas/2024

# GSoc

https://discourse.ros.org/t/attention-students-open-robotics-google-summer-of-code-2024-projects/36271

https://developer.blender.org/docs/programs/gsoc/2024/

https://www.haiku-os.org/blog/zardshard/2024-05-08_gsoc_2024_plans_for_fixing_haikus_webkit2_port/

https://hepsoftwarefoundation.org/activities/gsoc.html

https://github.com/opencv/opencv/wiki/GSoC_2024#idea-Neural-3D-Capture-and-Rendering

https://wiki.mozilla.org/Community:SummerOfCode19

https://python-gsoc.org/ideas.html

https://wiki.linuxfoundation.org/gsoc/google-summer-code-2024

https://wiki.qemu.org/Google_Summer_of_Code_2024

https://community.kde.org/GSoC/2024/Ideas

https://gsoc.gnome.org/

https://gradle.github.io/community/events/gsoc/

https://github.com/search?q=GSoC&type=issues&p=3

https://summerofcode.withgoogle.com/programs/2024/projects

https://mentorship.lfx.linuxfoundation.org/#my-tasks

# remote

https://clickhouse.com/company/careers

# startup

https://www.fermyon.com/

https://github.com/envoyproxy/envoy

https://www.fastly.com/about/careers/current-openings/

Tetrate

Fastly

# Linux Foundation Mentorship

https://mentorship.lfx.linuxfoundation.org/#my-tasks


# Support clang plugins on windows LLVM

Description of the project: The Clang compiler is part of the LLVM compiler infrastructure and supports various languages such as C, C++, ObjC and ObjC++. The design of LLVM and Clang allows the compiler to be extended with plugins[1]. A plugin makes it possible to run extra user defined actions during a compilation. Plugins are supported on unix and darwin but not on windows due to some specifics on the windows platform.

The general work that needs to be done is to annotate all the public API surface with __declspec(dllexport) and similar if they are being built as a dynamically linked library (and nothing if being built statically). When the library is being consumed the attribute on the same declaration must be __declspec(dllimport) or the same spelling for the GNU version for ELF and MachO. Note that the attribute changes between the implementation and consumer and between static and dynamic linking. This is normally controlled by expansion to a macro.

Expected result: This project aims to allow make clang -fplugin=windows/plugin.dll work. The implementation approach should extend the working prototype [3] and extend the annotation tool [4]. The successful candidate should be prepared to attend a weekly meeting, make presentations and prepare blog posts upon request.

Further reading [1] https://clang.llvm.org/docs/ClangPlugins.html

[2] https://discourse.llvm.org/t/clang-plugins-on-windows

[3] https://github.com/llvm/llvm-project/pull/67502

[4] https://github.com/compnerd/ids

Project size:Either medium or large.

Difficulty: Medium

Confirmed Mentor: Vassil Vassilev, Saleem Abdulrasool 3




React/Next/Typescript Flux Redux BootStrap, ANT Design, Tailwind Babel, Webpack, NPM

Ideally worked on Web Applications like SaaS, doing React front-end components.

React, GitHub, Java, Gradle, Groovy, MySQL, Snowflake, Docker, AWS, Slack, and JIRA

NodeJS NestJS MySQL MongoDB ReactJS NextJS Bootstrap/Material REST APIs Docker TDD CI/CD JEST/ Mocha, Jenkins, Selenium Stripe, RabbitMQ, Redis, AWS Elasticsearch

Use of Docker in local and production environments

Python, Java, or C++ TensorFlow, Caffe, PyTorch, Keras, Scikit Learn, and Theano

Python, Ruby on Rails, React.js or React Native

Python, Django, React, AWS/OpenStack, MySQL, MongoDB, PostgreSQL, Debian Ubuntu Debian/Ubuntu servers, Terraform, Vault, Packer, Prometheus, ELK, Docker RabbitMQ, Redis & Elasticsearch IOS & Android

NodeJS/Rails/django/go/elixir/java/flask/laravel

Java, Kotlin and the Android SDK, Android Studio, Material Spec

.NET, C#, SQL Server, IIS

figma HTML CSS Next.js, Apollo GraphQL, React

AWS, Azure, Google Cloud

MySQL, PostgreSQL, MongoDB

JavaScript and TypeScript

Git Node.js Docker, Kubernetes

Four or more years of experience in two or more of the following skill sets:
Ruby (Rails)
Go and related tooling
JavaScript (React, TypeScript, Relay)
MySQL and database management
NodeJS development
Design and build REST and/or GraphQL APIs
Experience with CI/CD tools and automated pipelines
Preferred Qualifications
Experience with Git, GitHub , Actions & workflow platform for version control and collaborative development.
Internals of web development frameworks, tools, and client performance optimization.
Building developer tools and pipelines that streamline and automate software lifecycle, including development, testing and releasing, with focus on speed, reliability and scalability.
Excellent written and verbal communication via async collaboration, documentation, and visibility of work
Hands-on experience with distributed systems at global scale.
Experience working with a remote, distributed team.
Familiarity with SQL, Kusto Query Language, general database knowledge, Kubernetes, and/or cloud-native concepts
Passionate about fostering effective Engineering practices and processes and contribute to open source software, engage with maintainers, and actively participate in community curation.
Compensation Range: USD $104,400.00 - USD $276,900.00 /Yr.

In addition, certain roles also have the opportunity to earn sales incentives based on revenue or utilization, depending on the terms of the plan and the employee's role.


A bachelor/master in Informatics (or related);
Proven professional experience in OO programming and web development;
Attentive to details, delivering quality code which is maintainable, efficient and reliable;
Experienced in MySQL, or other relational databases;
Familiar with version-control and automated testing tools;
Used to work in JSON/XML/CSV formats and have no issues with HTML/CSS;
Experienced in Ruby or Ruby and Rails (the right candidate will be considered without this experience);
Good in English communication and teamwork.

1+ years of experience with a Javascript framework (VueJS, Alpine)

MySQL
Modern PHP: composer, PHPUnit, Laravel
Javascript: VueJS, Alpine JS, Webpack, NPM, Node
CSS, Tailwind
Familiarity working with Bash/Shell, Git, Docker, Kubernetes, testing frameworks

3+ years of software development experience
Strong computer science fundamentals and programing skills
Experience with IPASS platforms such as Mulesoft, Boomi and Workato
Experience managing software development in an agile environment with CI/CD and automated testing – CirlceCI, Jenkins, CodePipeline, ElasticBeanstalk, GitHub Actions
Proficiency in programming languages JavaScript/TypeScript, Python, SQL
Working knowledge of React and REST API’s
Strong experience developing large-scale modern architectures in AWS
Strong knowledge on RDMS and NoSQL database technologies in AWS
Experience in data strategy – warehousing, ELT – Snowflake, RedShift, BigQuery

Required

Bachelor's degree and less than 2 years related experience.
Knowledge of software QA / test methodologies and process.
Familiarity with Java, Maven and Selenium.
Familiarity with issue/bug tracking systems, such as JIRA.
Excellent oral and written communication skills.
Preferred

Familiarity with one or more of the followings: Javascript, DOM HTML and React Native (or AngularJS).
Knowledge of SQL, Shell scripting, Cloud platforms.
Knowledge of API testing.
Knowledge of working in agile product teams (Scrum and Kanban)


Entry Level / Intern Embedded Linux / Yocto Engineer
Konsulko Group has an entry level or intern opening for an embedded Linux and/or Yocto build
system engineer. Join and learn from a team of Linux engineers with a history of Linux development
dating back to the mid 90s.
The position is ideally based at our engineering center in Sofia, Bulgaria, but other locations will be
considered as well.
Job Requirements:
• A Passion for Linux
• B.S. or MS in Computer Science or similar major
• Experience in using Linux as a development platform
• Proficient in C programming
• Some Yocto Project, bash, or Python experience a plus
• Bonus points for having developed or debugged any kernel drivers, and any community
contributions
• Familiarity with Git
• Strong analytical and problem-solving skills
• Good English verbal and written skills
Please send your CV or resume in pdf form to careers@konsulko.com. 

Senior Embedded Linux/Yocto Engineer
Konsulko Group is looking for an experienced candidate with background in embedded Linux and
Yocto/OE to help migrate, develop, and maintain Yocto-based platforms. The candidate will be
responsible for tracking Yocto Project, various versions and packages, as well as engage with the
Open Source community to upstream any specific changes. The candidate must have experience
with embedded systems, device drivers, kernel modifications, and boot loaders.
The position may be based at our engineering centers in Sofia, Bulgaria or Malmö, Sweden, or the
Senior Engineer may choose to live in his/her home country, or elsewhere in North America, Europe
or Asia.
Primary Responsibilities:
• Develop and migrate existing products to Yocto-based platforms.
• Work closely with Konsulko’s customers to track and integrate specific Linux/Kernel
infrastructure and any third-party drivers in their software stacks.
• Maintain and support Yocto build system in a continuous integration environment including
packaging and deployment of software images.
• Write and maintain scripts
• Configure, modify and integrate the kernel and embedded boot loaders.
Job Requirements:
• A Passion for Linux
• B.S. in Computer Science and 7 years related work, or M.S. in Computer Science and 5 years
related work experience.
• 3+ years of Embedded Linux Systems experience.
• Proficient in C programming.
• Substantial experience with Yocto Project
• Experience with Bash scripting and Python programming.
• Experience developing and debugging kernel drivers for Embedded Linux would be a plus
• Familiarity with Git.
• Strong analytical and problem-solving skills.
• Excellent English verbal, written, and documentation skills.
Please send your CV or resume in pdf form to careers@konsulko.com. 
