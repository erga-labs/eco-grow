# EcoGrow - Smart Agriculture System

## About
EcoGrow is an innovative smart agriculture system that leverages edge computing, machine learning, and IoT technologies to provide comprehensive agricultural support. By integrating advanced machine learning models with ESP32 microcontrollers and PocketBase database, the system offers farmers intelligent insights for crop management, environmental monitoring, and precision farming.

## Team Members
- Nishumbh Shah (DY22ENGU0AID067)
- Siddharth Sahani (DY22ENGU0AID046)
- Luqmaan Shaikh (DY22ENGU0AID069)
- Dev Tangadi (DY22ENGU0AID081)

## Problem Statement
Agricultural productivity is complex and depends on multiple interrelated factors. Traditional farming methods lack:
- Real-time environmental insights
- Predictive crop management capabilities
- Advanced disease detection mechanisms
- Data-driven decision-making tools

## Objectives
- Develop a comprehensive smart agriculture system with multiple intelligent modules
- Implement predictive analytics for crop selection and management
- Create a scalable platform for continuous agricultural intelligence
- Provide actionable insights through advanced machine learning models

## Key Features
- **Microcontroller**: ESP32 as primary data collection and processing unit
- **Database**: PocketBase for efficient data storage and retrieval
- **Sensors**: 
  * NPK (Nitrogen, Phosphorus, Potassium) sensors
  * Humidity sensors
  * Temperature sensors
- **Machine Learning Models**:
  1. Time Series Forecasting
     - Predict suitable crops based on current environmental conditions
  2. Crop Management Advisor
     - Recommend specific planting and maintenance strategies
  3. Crop Health Detection
     - Disease identification through photograph analysis

## Technology Stack
- **Hardware**:
  * ESP32 microcontroller
  * Environmental and NPK sensors
- **Database**: PocketBase
- **Application Framework**: Expo JS
- **Machine Learning**:
  * Python
  * TensorFlow Keras
- **Model Deployment**: Custom API for model interactions

## Methodology
1. **Data Collection**: 
   - Continuous environmental data gathering using ESP32 and sensors
   - Photograph collection for crop health monitoring
2. **Data Processing**: 
   - Cleaning and normalization of sensor and image data
   - Feature extraction for machine learning models
3. **Model Development**:
   - Time series forecasting model
   - Crop management recommendation system
   - Image-based disease detection model
4. **Integration**:
   - API development for model interactions
   - Expo JS application for user interface
   - PocketBase for data management

## Expected Outcomes
1. Intelligent crop selection based on real-time environmental conditions
2. Precise crop management recommendations
3. Early disease detection and intervention
4. Improved agricultural productivity and resource efficiency
5. User-friendly mobile application for farmers

## Innovation Highlights
- Edge computing with ESP32
- Multi-modal machine learning approach
- Integrated agricultural intelligence platform
- Real-time predictive analytics

## Technical Challenges
- Developing accurate time series forecasting models
- Creating robust crop disease detection algorithms
- Ensuring low-latency edge computing
- Designing intuitive user interfaces for farmers

## References
1. [Time Series Linear Forecasting for precise irrigation](https://ieeexplore.ieee.org/abstract/document/10454662)
2. [Forecasting Soil Moisture based on Time Series Analysis](https://www.mdpi.com/1424-8220/21/8/2656)
3. [Precision Agriculture using smart sensors](https://link.springer.com/chapter/10.1007/978-981-15-0313-9_11)
4. [Time Series prediction through data segmentation and clustering](https://www.atlantis-press.com/proceedings/iconnsmal-22/125987136)

## Project Status
This project is currently under active development as part of a semester V mini project at Ramrao Adik Institute of Technology, Department of CSE (AIDS Specialization).

---

**Note**: This README is a living document and will be continuously updated to reflect the project's progress and evolving capabilities.