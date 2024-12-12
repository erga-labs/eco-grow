# EcoGrow Machine Learning Models

## Overview
Machine learning models for the EcoGrow Smart Agriculture System focusing on crop prediction, management, and health detection.

## Environment Setup
- Python 3.12
- Virtual Environment Recommended

## Installation
1. Clone the repository
2. Create virtual environment:
   ```bash
   python3.12 -m venv venv
   source venv/bin/activate  # On Windows use `venv\Scripts\activate`
   ```

3. Install dependencies:
   ```bash
   pip install -r requirements.txt
   ```

## Project Structure
- `models/`: Machine learning model implementations
- `dataset/`: Dataset storage

## Models

1. **Crop Management Advisor**
   - Recommends pesticides, irrigation strategies
   - Trained on agricultural best practices

> TO BE IMPLEMENTED

2. **Time Series Forecasting**
   - Predicts suitable crops based on environmental conditions
   - Uses LSTM and Time Series segmentation

3. **Crop Health Detection**
   - Image-based disease identification
   - Convolutional Neural Network (CNN) implementation

## Training and Evaluation
- run `model.ipynb`
<!-- 
## API Deployment
- FastAPI for model serving
- Run API server:
  ```bash
  uvicorn main:app --reload
  ``` -->

## Environment Variables
Use `secrets.example.py` to get environment variables

## Logging and Monitoring
- Uses Python logging

## Contributing
1. Fork the repository
2. Create feature branch
3. Commit changes
4. Push to branch
5. Create Pull Request

## Licensing
Refer to the project's main LICENSE file