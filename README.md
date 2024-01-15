# Bare Metal Embedded Systems Programming Journey

## Introduction
Welcome to my repository documenting my journey in bare metal embedded systems programming. I am Lotfi Bouteraa, a passionate learner eager to explore the intricacies of low-level programming for embedded systems.

## Learning Goals
My primary goals in this journey include:
- Understanding the fundamentals of bare metal programming.
- Exploring real-world applications and challenges in embedded systems.
- Building hands-on projects to solidify my knowledge.

## Roadmap
Here is a high-level roadmap of topics I plan to cover:
1. Introduction to Bare Metal Programming
2. Microcontroller Architecture and Memory Management
3. GPIO and Peripheral Control
4. Interrupts and Timers
5. Communication Protocols (I2C, SPI, UART)
6. Device Drivers and Firmware Development
7. Real-time Operating Systems (RTOS)
8. Embedded System Debugging and Optimization

## Resources
I will be using various resources to guide me through this learning journey. Some of the key resources include:
- Books
- Online Courses
  
## Progress Tracking
I will regularly update this README to track my progress, share insights, and document challenges and solutions encountered during the learning process.

## Projects
Explore the `projects` directory to find hands-on projects I've implemented in the course of my learning journey.

## Notes
Check the `notes` directory for detailed notes on specific topics, code snippets, and reflections.



## License
This repository is licensed under the [MIT License](LICENSE.md).

---

## Progress 
When working with microcontrollers, understanding the compilation process becomes crucial. In typical scenarios, developers use integrated development environments (IDEs) for C/C++ projects, often hosted on the same machine (PC) they are using. However, in real-world projects, especially those involving microcontrollers, cross-compilation is prevalent.

Cross-compilation involves creating a project on one machine while the project is intended to run on a different architecture or platform. In the case of microcontrollers, the development might occur on a more powerful computer (host machine), while the target machine is the microcontroller with its specific architecture and constraints.

This process ensures that the compiled code is compatible with the microcontroller's architecture and environment. The generated binary, rather than being executed on the development machine, is transferred to the microcontroller for execution. Cross-compilation is essential in embedded systems and microcontroller development to account for resource limitations and hardware variations.

So, the first thing you need to get your hands on is the ARM GNU Toolchain. You can grab it from ARM's official website. Depending on your operating system, you download and install it. In my case, since I'm using the Windows Subsystem for Linux (Ubuntu), I just run these commands in my terminal:
```
sudo apt -y update
sudo apt -y install gcc-arm-none-eabi make stlink-tools git
````
Now, let's talk about each of these tools:

1- gcc-arm-none-eabi:
This is your go-to tool for turning your source files, essentially everything in your project folder and its dependencies, into object files. It's your compiler in the ARM GNU Toolchain.
![Figure-2-1-1024x524](https://github.com/lotfibtr2/bare-metal-embedded-journey/assets/62564371/5ff42075-619c-4a3b-aec3-64ffbc30896a)

2- make:
Consider Make as your reliable assistant, diligently managing the entire build process. It automates the compilation and linking tasks, ensuring that only the essential components are recompiled when you make changes to your code. Inside the Learnings/code folder, you'll find a straightforward and very basic Makefile example. It's worth noting that the Makefile may vary from project to project, adapting itself continuously to the specific needs and structure of each coding endeavor.
````
CC=arm-none-eabi-gcc 
MACH=cortex-m4
CFLAGS = -c -mcpu=$(MACH) -std=gnu11 -mthumb -O0

firmware.o:main.c
	$(CC) $(CFLAGS) main.c -o firmware.o
````
And now I will show you the use of it.
Without Makefile we would compile our code like this:
````
$arm-none-eabi-gcc -mcpu=cortex-m4 -std=gnu11 -mthumb -O0 -c main.c -o firmware.o
````
And now after having the Makefile separately:
````
$make
````

3- stlink-tools:
These are like the magic wand for STM32 microcontrollers. They help you flash your compiled binary onto the microcontroller's memory and assist in debugging. Essential tools for making your code work on the actual hardware.

4- git:
This is your version control buddy. Git tracks changes, manages different versions of your code, and makes collaborating with others a breeze. While not directly involved in compiling, it's a lifesaver for keeping your project organized and collaborating with fellow developers.

Since we are still at the beginning of the journey we know that having a solid knowledge of what is happening in the backend is vital to understand more complex and advanced topics that we are going to study along the journey, After compiling the source files we get the .o file,that we can see the sections in that file by throwing this command in the terminal:
````
arm-none-eabi-objdump -h firmware.o
````
We are going to see: 
````
firmware.o:     file format elf32-littlearm

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .text         0000000c  00000000  00000000  00000034  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
  1 .data         00000000  00000000  00000000  00000040  2**0
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000000  00000000  00000000  00000040  2**0
                  ALLOC
  3 .comment      00000034  00000000  00000000  00000040  2**0
                  CONTENTS, READONLY
  4 .ARM.attributes 0000002e  00000000  00000000  00000074  2**0
                  CONTENTS, READONLY
````
This might look confusing at first but we are going to discuss it step by step. Before we deep dive into this we should know that in our projects we will have many files and not just one, while compiling, the last step is called linking which bring for example ````main.o```` and ````led.o```` and make so-called ````finaleExecutable.o````.
The ````linker```` is used to merge all similar sections of different object files, that's what the previous section is about:
````
main.c --> main.o {.text, .data, .bss, rodata}-->
                                                                             -->{.text(.text(main.o), .text(led.o)}
	 					         finalExecutable.elf -->{.data(.data(main.o), .data(led.o)}
			 						     -->{.bss(.data(main.o), .bss(led.o)}
								             -->{.bss(.data(main.o), .bss(led.o)}		
led.c -->led.o {.text, .data, .bss, rodata}----->
````
We also have the so-called ````Locator```` which is a part of the linker and it is how you wish to merge different sections and assign adresses to different sections.




Happy coding!
