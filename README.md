# Template for CPSC2720 Two Week Project

last update:  2022-09-23 by Aayush patel [ap.patel@uleth.ca]

Team  Members: Aayush patel [ap.patel@uleth.ca]
               Ramya patel [ramya.patel@uleth.ca]
               Kamesh patel [kamesh.patel@uleth.ca]
               Kelechi Anyanwu[kelechi.anyanwu@uleth.ca]

Process of  creating the design: 
 1.  We started by deciding & learning the basic curve of making design. 
 2. Grabbed over some basics on the dia software to create our designs.
 3. we decided to each make a design by the end of sunday night & at the end of the day we made the  final designs & decided on 2 best designs.

#implementation steps:
 Aayush completed player.hpp & player.cpp [complications discovered & tackeled: styleCheck]
Ramya Patel has updated on game session
Notes:

* The Makefile and .gitlab-ci.yml files are provided.
* The .gitlab-ci.yml file uses the targets in the Makefile.
* These are the tools/commands/apps used:
  * Compiler: g++ 
  * Style Check: cpplint
  * Static Check: cppcheck
  * Memory Check: valgrind
* Use `make version` to see the versions of the tools.

Certain assumptions have been made:
* One repo contains the files for one project.
* All header files for the project are found in <code>include/</code> and named <code>*.hpp</code>, every class must have a header file.
* All project source files for the project are named <code>*.cpp</code>.
  * Any needed source files that correspond to header files are found in <code>src/</code>.
  * There is a <code>main.cpp</code> found in <code>src/project/</code>.
