# Greeting Humanoid Robot

This project implements a greeting humanoid robot using ROS (Robot Operating System) and Gazebo simulation environment. The robot is designed to detect a person using a camera, approach them, and greet them verbally.

## Overview

The robot utilizes a combination of perception, navigation, and speech capabilities to achieve the greeting behavior. The system architecture is as follows:

1. **Person Detection:** A camera mounted on the robot detects a person using computer vision techniques. 
2. **Navigation:** Upon detecting a person, the robot plans a path towards them using ROS Navigation Stack.
3. **Greeting:** Once the robot reaches the person, it triggers a speech synthesis module to greet the person verbally.

## Implementation Details

### Robot Model

The robot model used in this project is a custom-designed humanoid robot built in URDF (Unified Robot Description Format). The robot is equipped with:

- **Camera:** A simulated camera for person detection.
- **Mobile Base:** A differential drive base for navigation.
- **Speaker:** A simulated speaker for speech output.

### ROS Packages

The project is organized into several ROS packages:

- **greeting_humanoid_robot_description:** Contains the URDF model of the robot.
- **greeting_humanoid_robot_gazebo:** Provides launch files and configurations for simulating the robot in Gazebo.
- **greeting_humanoid_robot_navigation:** Implements the navigation stack for path planning and robot control.
- **greeting_humanoid_robot_perception:** Handles person detection using the camera feed.
- **greeting_humanoid_robot_speech:** Provides speech synthesis functionality for greeting.

### Workflow

1. **Launch Simulation:** Start the Gazebo simulation environment with the robot model loaded.
2. **Person Detection:** The perception package subscribes to the camera topic and processes the image to detect a person.
3. **Navigation:** Once a person is detected, the navigation package plans a path towards the person and controls the robot's movement.
4. **Greeting:** When the robot reaches the desired proximity to the person, the speech package synthesizes a greeting message and publishes it to the speaker topic.

## Dependencies

- ROS (Melodic or Noetic)
- Gazebo
- ROS Navigation Stack
- OpenCV (for person detection)
- Festival (or other text-to-speech engine)

## Installation

1. Clone the repository: `git clone https://github.com/arupa444/greeting-humanoid-robot.git`
2. Create a ROS workspace and build the packages: `catkin_make`
3. Source the workspace: `source devel/setup.bash`

## Running the Simulation

1. Launch the Gazebo simulation: `roslaunch greeting_humanoid_robot_gazebo greeting_humanoid_robot.launch`
2. (Optional) Run the person detection node: `rosrun greeting_humanoid_robot_perception person_detection`
3. (Optional) Run the navigation node: `roslaunch greeting_humanoid_robot_navigation move_base.launch`

## Results

The robot successfully detects a person in the simulated environment, navigates towards them, and greets them verbally. The project demonstrates the integration of different ROS components to achieve a complex robotic behavior.

## Some Photos while working

![CTTC Lab](IMG20220405180921.jpg)  
![CTTC Lab](IMG20220326192859.jpg)   
![CTTC Lab](IMG20220405180911.jpg)   
![CTTC Lab](IMG20220405180916.jpg)   
![CTTC Lab](IMG20220405180927.jpg)  

## Future Work

- Implement more robust person detection algorithms.
- Integrate gesture recognition for more interactive greetings.
- Add obstacle avoidance capabilities to the navigation stack.
- Explore using a more sophisticated text-to-speech engine for natural-sounding speech.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
