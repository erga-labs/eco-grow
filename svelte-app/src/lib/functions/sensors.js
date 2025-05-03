export const getSensors = () => {
    return ["ABC-123"];
};

export const getDataForSensor = (sensorId) => {
    return {
        currentCrop: "Tomato",
        currentValues: {
            nitrogen: 73,
            potassium: 67,
            phosphorus: 80,
            moisture: 50,
        },
    };
};
