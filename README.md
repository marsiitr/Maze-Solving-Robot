# Maze-Solving-Robot
Srishti 2020

## Abstract

The Maze Solving Bot is a wireless bot. It is capable of solving any 2-D maze with the help of live video feed parsed by a python script. The speciality of this bot is that it can adapt itself to any maze and not one-kind in particular. Having a Four-wheel Omni drive, It aims to reach the ending point in the shortest time. If there are more than two ways out, then it works to solve the shortest path.

![Final Product](https://github.com/shan-mathi/Maze-Solving-Robot/blob/master/Images%20and%20Videos/Images/Maze_solving_robot.jpeg)

## Motivation

<p align="justify">Maze solving bot is a simple and straightforward case where we can learn and experiment about path planning. The standard method of maze solving takes much time due to its trial and error methods. With the help of shortest path detection and robot live coordinates mapping, we look forward to improvising the olden methods.<br><br>A maze in the real-world can represent roads and traffic. All of us want to know the best way to go to work, school etc.  In the journey, we experience all sorts of obstructions like traffic, diversions, intersections and dead-ends. This project gives us an insight into how to solve this problem. It helps us find the best and the shortest path to avoid these barricades as much as possible.</p>

## Components

* 2x Motor Driver L2899
* 4x DC () rpm Motors
* Nodemcu Esp8266
* 1x 12V DC Power Adapter
* 3D printed Chassis
* 4x Omni Wheels


## Workflow

![Worflow Diagram](https://github.com/shan-mathi/Maze-Solving-Robot/blob/master/Images%20and%20Videos/Images/Workflow.jpeg)

## Mechanical Aspect of the Design

### Chassis

![Chasis](https://github.com/shan-mathi/Maze-Solving-Robot/blob/master/Images%20and%20Videos/Images/Chassis.JPG)

<p align="justify">The main body of the robot is 3D printed using PLA(Polylactic Acid). It has the shape of a ‘plus’ sign. The dimensions of the chassis are about 14.5cm x 14.5cm x 5 cm. There are lightening holes present wherever possible to keep the weight of the chassis less</p>

### Drive type

![Drive _type](https://github.com/shan-mathi/Maze-Solving-Robot/blob/master/Images%20and%20Videos/Images/Drive_type.jpeg)

<p align="justify">The maze solving bot uses a 4 wheeled Omni type of drive. 2 sets of Omni wheels are perpendicular to the other set. The reason for this design is that the maze only consists of perpendicular junctions. Hence the working of the robot is highly simplified if we use 4 WD Omni.<br><br> 4 WD Omni in general has some limitations. It only takes 3 points to define a plane. Hence in most practical cases, the 4th wheel lies out of the plane. But in this project, we could dodge this limitation by 3D printing the chassis thus making it highly accurate.</p>


## Electronics Aspect of the Design

### Actuator

The robot uses four 12 volt- 100 rpm motors. These motors are relatively light, weighing a few hundred grams and overall have a small and compact size. Having a small body size is imperative for the robot to transverse through the narrow lanes of the maze..

### Microcontroller

* One of the biggest benefits of the NodeMCU is that it allows communication over a wifi-network, hence there is no need to keep it plugged into the device on which the source code is, the instructions can be easily sent over a wifi network.
* This allows the execution of the PID control equation to a significantly higher degree of precision.
* Completing both the tasks of receiving coordinates and controlling motors is done by Nodemcu. Coordinates are detected by scanning QR code.


### PID Control

* The PID control allows monitoring the progression of errors in the movements of the robot and making minute changes in the operation of the actuators to ensure a greater degree of precision in the robot’s movements.
* In our case, the robot had to move parallel to the co-ordinate axis only on a flat surface with minimal skidding of the wheels. This simplified our job many-fold, since now we focus only on the “proportional errors”, without considering the derivative of the integral terms.



## Cost Structure

| *Components*                    |*Cost(INR.)*|
|-----------------------------------|------------|
| 2x Motor Driver L2899                        | 250       |
| 2x DC () rpm Motors       | 700        |
| Nodemcu Esp8266                      | 350        |
| 12v Battery                        | 1000        |
| 3D printed Chassis               | 800       |
| 4x Omni Wheels                         | 2200       |
| *Total*                         | *5300*  |

## Applications

* Reduce manual labour in waiting in hotels and in deliveries.
* Can be used in parking lots to direct the cars to the closest empty space.
* Future of driving is self-driving cars or fully automated cars 

## Limitations

* The Camera that we are using for image processing is attached to our laptop with wires, so that might become a bit hectic to handle.
* There has to be a minimum height above which Camera should be mounted, so for our maze solving bot show we need a spacious room, and we have to deal with a bunch of extra wires.

## Future Improvements

* Sensors can be added to the bot to avoid further immediate obstacles.


## Team Members

1. Akshat Gupta
2. [Sarthak Surolia](https://github.com/sarthak1420)
3. Sidhhart Gehlot
4. [Shanmathi Selvaraj](https://github.com/shan-mathi)
5. [Sneha Jain](https://github.com/snehajain02)
6. [Susmit Walve](https://github.com/susmitwalve)
7. [Suhani Jain](https://github.com/jainsuhani317)
8. [Yash Asati](https://github.com/yashasati53)

## Mentors

1. [Sanjeev Krishnan R.](https://github.com/SanjeevKrishnan)
2. Shubham Malviya

## References

<https://www.learnopencv.com/opencv-qr-code-scanner-c-and-python/>

<https://youtu.be/0u78hx-66Xk>

<https://github.com/marsiitr/DIC_Terrace_Farming>

<https://www.instructables.com/id/Controlling-Arduino-with-python-based-web-API-No-p/>



