import { pb } from "$lib/server/db/pocketbase";
import { json } from "@sveltejs/kit";

export async function GET() {
    const pbResp = await pb.collection("mp_plant_info").getFullList();

    const crops = [];
    pbResp.forEach((crop) => {
        crops.push(crop.plant);
    });

    return json({ crops });
}
