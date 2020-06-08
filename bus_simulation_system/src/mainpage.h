// Copyright 2020 Pengyin Chen

#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_

/*! \mainpage Bus Simulation
 *
 * \section intro_sec Introduction
 *
 * This is the introduction.
 * This program simulates the process of a bus system
 * It provides the user interface and several functionalities
 *
 *\section Instruction
 * to obtain: pull from Github
 *
 * to compile: 1.change to src directory
 * 2.run make
 * 3.return to project directory
 * 4.run ./build/bin/vis_sim <port number>
 * 5.open your web browser
 * 6.visit http://127.0.0.1:<port number>/web_graphics/project.html
 *
 * to run simulation:
 * 1.choose your desired settings
 * 2.click on start
 * 3.you will see the bus is moving
 * 4.if you wanna pause click "pause"
 * 5.if you wanna resume click "resume"
 *
 * \section Discussion
 *
 * \subsection Two different type of bus factory
 * There are two different types of bus factory design: abstract and concrete.
 *
 * For concrete factory design, we will create 3 subclasses of Bus class,
 * they are BT_Large, BT_Small, and BT_Regular,
 * then we create a BusFactory class with only to functions: create() and report().
 * Since we will need some flag value to determine which type of bus we are going to create,
 * we will not input the value of capacity, instead we need an int value called bt(bus type)
 * as a flag of bus size.
 * In create() function, we use a Bus* as a generic pointer
 * then we match the flag value to decide the size of the bus,
 * then create a subclass object and assign it to the pointer and return it.
 * Also, in this version of bus factory, we use a random number generator as the bus flag.
 *
 * For abstract factory design, we will be an abstract class called AbstractBusFacory subclass
 * There is an abstract method called create() inside the AbstractBusFacory class,
 * then we create 3 subclasses of AbstractBusFacory called SmallBusFactory, RegularBusFacoty and LargeBusFactory.
 * Also, to match the three types bus factories, we create 3 subclasses of Bus class.
 * They are BT_Large, BT_Small, and BT_Regular.
 * For each subclass of AbstractBusFacory, they override the create() function to build specific bus
 * alone with the report() function.
 *
 * \subsection bfi bus factory implementation
 * In this bus simulation project, it uses a concrete factory design pattern.
 * There are several files related to this bus facoty
 * BT_Small.cc, BT_Regular.cc, BT_Large.cc,
 * BT_Small.h, BT_Regular.h, BT_Large.h,
 * BusFactory.cc, BusFactory.h,
 * There are three subclasses called BT_Large, BT_Small, BT_Regular inherit the bus class.
 * Each of them will have a constructor without the parameter of capacity,
 * but it will initialize the base class with certain capacity.
 * in the BusFactory class, there are two methods, create() and report()
 * in method create(), it takes all parameters of a bus constructor without capacity
 * instead, it adds a bus type flag
 * based on different flag value of bus type, it will create an object of different subclasses
 * then assign it to a Bus* type pointer and return
 *
 * \subsection pcs pros/cons of two different factory type
 * for concrete bus factory
 * pros: create fewer classes, compatibility that you can create different types of buses with only one bus factory
 * cons: you are not sure which kind of buses you are doing to  create
 * for abstract bus factory
 * pros: you can make sure which sub factory is creating which kind of bus
 * cons: code is more complicated than concrete types
 *
 *
 * \subsection wi why I choose the concrete type
 * because could build less subclasses and code is not complicated so that we could have a low coupling programming.
 *
 * \subsection Writing/discussion about the structure of the domain elements.
 * For this simulation, we can first dfvide the programing to two parts: frontend and backend.
 * Frontend provides us a user interface so that users could interact with the program and have a better visual Simulation.
 * Backend have a server deal with the command that user requests which is mainly the visualization_simulator class.
 * VisualizationSimulator class receieve certain commands like start, pause/resume, and call corresponding functions.
 * Those funcitons will go back to all foundmental elemments we implemented in src directoty like bus, route, stops and so on.
 * 
 * \subsection ds Desiging and Implementing the Observer Pattern 
 * For this observer design, I choose to use classic template of observer pattern which includes a observer class(IObserver),
 * a subject class(IObserverable). The Observer Pattern could connect subjects with observers
 * so that one subject changes state, all of its observers are notified and updated automatically. IObserver class provides an interface to
 * to BusWebObserver class in this project. IObserverable class contains three methods: RegisterObservers(IObserver *observer) which take an observer as parameter.
 * ClearObservers(), and NotifyObservers(BusData* info) which take bus data as the input. RegisterObservers() could add the observer to the list. Clear() could clear the list.
 * NotifyObservers() could send info to every observers in this list. There is a class in my_web_server_command called BusWebObserver. Since bus class inherits IObservable class,
 * so each bus is a subject. BusWebObserver associated with buses. For each bus, we can add some observers, clear observers, and notify them. To add an observer, we add a new method
 * in VisualizationSimulator class called ClearListeners() and AddListener(std::string* id, IObserver* observer). ClearListener() is straightforward. AddListener() takes a bus id and
 * an observer as parameter so that AddListener() could add an observer to a specifc bus. To achieve the notify functionality, we choose to add updateObservers() function in bus class update method
 * so that every time the bus data get updated, it will updateObservers and inside the updateObserver() function, we call notifyObservers, In this way, we achieve our goal and build an observer-subject relationship.
 *
 * \subsection tt Hard part of this design 
 * I think the hard part of this design is to where should add new method updateObserver() in the bus class, and how we could set up the interaction in the VisualizationSimulator. Most importanly, it is the concept.
 * I have a hard time trying to figure out the relationship between Iobserver and Iobserverable. I do not how to connect with VisualizationSimulator class. I also have some trouble with my coding since some compile error
 * drives me crazy. 
 * One of the most helpful resource is the lecture code I got from canvas. It shows the relationship of shop, subject, and some objects. Attach, detach, notify methods are very similar and not complex. 
 * The shop inherit the observer class, some other subjects inherit Subject class. Each subject could attach some shop which are the observers, and they can also detach and notify them.
 * This design example give me the inspire to design my pattern for IObserver and IObservable.
 * 
 * \image html Observer_UML.jpg "Observer Pattern Design" width=1024px
 *
 * \subsection tm Designing and Implementing the Decorator Pattern
 * For this decorator pattern design, I choose to follow the template we have in class to change the color of buses.
 * First, I create an IBus interface that only contains changeColor() and changeDensity() virtual methods.
 * changeColor() is to set the color of each bus, and changeDensity() is called when we need to change the intensity of the color. 
 * Then, I changed the bus class to inherit the IBus class. Then I build a BusDecorator class to inherit the IBus class but with an Ibus pointer called m_Bus, and two methods mentioned above.
 * Instead of simply change the color, the two methods change the color by calling the IBus pointer's methods to change the IBus's color.
 * In BusDecorator class, the constructor initialized with an IBus pointer, and also initialize the base class.
 * So we can combine the BusDecorator with a Bus and calling the changeColor() and changeDensity() to change the bus's color and density of color.
 * How to change the bus color and density is to do the following: when we create a new bus in the visualization_simulator, we add a default color to it.
 * Then every time visualization_simulator call update function, we check if it is in outbound or not, then we create an IBus pointer, conbine BusDecorator with this bus and call this bus's changeColor() to set its color to maroon or gold since every bus is an IBus.
 * To change the color intensity, every time the visualization_simulator calls update method, it updates each bus. Then we check each bus's passenger and based on that we call changeDensity() to change the color.
 *
 *  \image html Decorator_UML.jpg "Decorator Pattern Design" width=1024px
 *\subsection cl The classes and methods you had to add and where you had to add them
 * For this singleton pattern, I add IBus class which contains only two virtual methods: chanegColor() and changeDensity().
 * BusDecorator class contains the implementation of the two methods by using an IBus pointer and within the two methods, we use the pointer to call changeColor() and changeDensity().
 * In bus class, I added the implementation of changeBus() and changeDensity() as setters to change the color and intensity.
 * Also, I add a method called isOutbound() to check if this bus is in outbound or not.
 * For IBus and BusDecorator, I added them in bus.h including the two methods. For the new methods of the bus class, the changeColor() and changeDensity() implemented in bus.h, and the isOutbound() is in bus.cc.
 * 
 * \subsection oo Pros and Cond of the one which you implemented and one which you did not implement
 * For the one I implemented, since I only have one BusDecorator class that could either change the color or the intensity. In this way, I separate the change color and change intensity.
 * Thus the pro is that the code has good cohesion, and loose coupling. When setting the color of each bus in VisualizationSimulator, it will be much easier for us to initialize the bus decorator and connect the bus and bus decorator.
 * The cons for the one I implemented is that if we want to add more change on color, we will have to add new methods and alter the code in the base class IBus, which violates the Open_Closed Principle. This kind of design is open to extension, but not closed on modification.
 * For the one I did not implement, which is to add new subclass for every change in color. In this case, it is to have two BusDecorators, and each could either change color or intensity. But for each class, it will have a subclass that could do another thing.
 * For example, if I have a decorator that could change the color, then I will add a subclass to change the intensity.
 * In this way, we can easily wrap the decorators and have the option to do double or more wraps. The pro is that it does not violate the Open-Closed Principle. It is open to extension and closed to modification.
 * The con for the one I did not implement is that it has a bad cohesion and high coupling. It looks very complex and if we have a lot of change on color, it will create way too many classes. Also, in some sense, we may not use them all and the maintain cost is also high in this kind of design.
 *
 *\subsection wp Which parts of the design and implementation were most difficult for you, and include any tips or advice on how to understand and implement the pattern
 * In this decorator design, I think the structure of classes is hard for me at the beginning to think about. Then I go back to the example on canvas, and trying to figure out how classes should be added and where should I use it. Finally, I come out up with the design I have for now. 
 * Looking at some examples shown online could also be helpful for you to really understand the decorator pattern.
 */

#endif  // SRC_MAINPAGE_H_
