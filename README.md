# Bare Metal Embedded Systems Programming Journey

## Introduction
Welcome to my repository documenting my journey in bare metal embedded systems programming. I am [Your Name], a passionate learner eager to explore the intricacies of low-level programming for embedded systems.

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
Think of Make as your assistant that takes care of the build process. It automates the compilation and linking tasks, making sure only the necessary components get recompiled when you make changes.

3- stlink-tools:
These are like the magic wand for STM32 microcontrollers. They help you flash your compiled binary onto the microcontroller's memory and assist in debugging. Essential tools for making your code work on the actual hardware.

4- git:
This is your version control buddy. Git tracks changes, manages different versions of your code, and makes collaborating with others a breeze. While not directly involved in compiling, it's a lifesaver for keeping your project organized and collaborating with fellow developers.




Happy coding!
