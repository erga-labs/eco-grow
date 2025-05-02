import { json } from "@sveltejs/kit";

export async function POST() {
    const data = `Choose the Right Plant for Your Environment: This is perhaps the most crucial step. Don't try to grow a sun-loving cactus in a shady, humid spot, or a moisture-loving fern in dry, sandy soil. Research the light, water, temperature, and soil requirements of the plants you're interested in and choose ones that are well-suited to the conditions you can provide, whether indoors or outdoors. Matching the plant to the place saves a lot of headaches and increases your chances of success dramatically.
    Provide Adequate Water (But Don't Overwater!): Water is essential for plant survival, but too much can be just as harmful as too little. The right amount of water depends on the plant type, the size of the pot or planting area, the soil type, and the environmental conditions. A good rule of thumb is to check the soil moisture a few inches down. If it feels dry, it's likely time to water. 
    If it's still moist, wait. Ensure pots have drainage holes to prevent waterlogging, which can lead to root rot. Ensure Sufficient Light: Plants need light for photosynthesis, the process they use to create energy. The amount and type of light needed vary greatly among plants. "Full sun" means at least 6 hours of direct sunlight per day, while "partial shade" means 3-6 hours, and "full shade" means less than 3 hours of direct sun (though many "shade" plants still need some indirect light). Observe where you plan to place your plants throughout the day to understand the light conditions and choose plants that will thrive there.`;

    return json({ data });
}
