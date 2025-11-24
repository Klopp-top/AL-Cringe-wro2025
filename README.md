# WRO 2025 Future Engineers - Team Al-Cringe

Welcome to the WRO 2025 Future Engineers project repository! This project contains resources and documentation for our participation in the World Robot Olympiad (WRO) 2025.

## Project Overview

This repository covers two main challenges we participated in:

- **Obstacle Challenge**: [Watch the Video](https://www.youtube.com/watch?v=WQUDPhRON0Q)
- **Open Challenge**: [Watch the Video](https://www.youtube.com/watch?v=bAk6IqeD8iM)

## Repository Structure

The code for our robot and simulations can be found in the following directories:

- **`code/`**: Contains the source code for our robot's functionality.
- **`docs/`**: Includes documentation, presentations, and design specifications.
- **`hardware/`**: Contains 3D and 2D models, photos of components, PCB designs, and schematics.

### Directory Details

- **`code/`**:
  - Source code for robot functionalities.
  - Libraries and dependencies.
  
- **`docs/`**:
  - Presentations outlining our strategy and design.
  - Technical documentation for understanding our code and hardware setup.

- **`hardware/`**:
  - **3D Models**: STL files for 3D-printed parts.
  - **2D Models**: CAD files for mechanical components.
  - **Photos**: Images of components and assembly.
  - **PCB Designs**: Gerber files and design files from PCBWay.
  - **Schematics**: Circuit diagrams and connections.

## Code (in a few lines)

function DriveRobot()
    Initialize PID_controller
    Initialize encoder

    while true do
        if no obstacle detected then
            Move forward using PID_control

            if green block on right then
                Keep moving forward
            else if green block on left then
                Turn left

            if last block is red then
                Turn right
            else if last block is green then
                Turn left
        else
            Stop

        if parked then
            Exit parking using encoder
    end while
end function
