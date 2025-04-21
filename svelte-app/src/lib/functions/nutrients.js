export const getNutrientsForCrop = async (crop) => {
    const resp = await fetch(`/api/nutrients?crop=${crop}`);
    const respJson = await resp.json();
    return respJson;
};
