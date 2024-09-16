# Test task for interview
## Intro
Application is demonstrating my skills with: C++, Boost, Qt, SQL
As a build system i used make, so it can be used on any Linux/UNIX device, use the latest make version.
P.S. Task1 using Qt, Task2 using Boost.

## Getting started
Firstly u need to check if Boost and Qt is installed on your device, i used MacOS, but this Applications is compatible with any Linux and UNIX systems.
I used Homebrew to install Qt(installing the latest Qt version)
```bash
brew install qt
```
Or(for linux)
```bash
sudo apt-get install qt6-default
```
Boost u need to install and build lib from sources, all guides is on official site https://www.boost.org/doc/libs/1_86_0/more/getting_started/index.html

And then set the BOOST_ROOT variable, here must be the path to the boost root dir with builded libs.

Then git clone the repo, and execute make command in dir where the sources and Makefile.
You will get the executable file!

## Screenshot that helps understand that program works

### Task1
<img width="1439" alt="dbcheck" src="https://github.com/user-attachments/assets/a0430ae5-3229-4701-9e5b-9968c2c8c1c6">
On the right side we can see the output.csv file that contains 1024 lines with 6 word 8 symbols each.
On the left side here is sqlite database that contains the same lines but in sqlite table.

### Task2
<img width="1076" alt="clientServer" src="https://github.com/user-attachments/assets/e5888208-1254-4e52-94a4-6aca6e9767cc">
On this screenshot we can see the responses of server to the clients request.

<img width="1439" alt="sizeAndTextComparasion" src="https://github.com/user-attachments/assets/2c17943b-5821-49f6-b9e7-b3b67bb213db">
Here we can see on the left site the file that server is sending to clien compared to the file that client receives, and see that they are the same.




