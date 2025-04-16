/*
Will contain functions required by the frontend regarding nutrients
These functions will actually call the API

- [X] getNutrientsForCrop
- [ ] getNutrientHistory
*/

export const getNutrientsForCrop = (crop) => {
    /*
    {
        nitrogen: number | string
        pottasium: number | string
        phosphorus: number | string
        moisture: number | string
    }
    */

    const r = () => Math.round(Math.random() * 100);
    return {
        nitrogen: r(),
        pottasium: r(),
        phosphorus: r(),
        moisture: r(),
    };
};
