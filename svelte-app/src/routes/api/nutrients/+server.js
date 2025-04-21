import { pb } from "$lib/server/db/pocketbase";
import { json } from "@sveltejs/kit";

export async function GET(req) {
    const crop = new URL(req.request.url).searchParams.get("crop");
    const pbResp = await pb.collection("mp_plant_info").getFirstListItem(`plant="${crop}"`);

    const nutrients = {
        nitrogen: pbResp.nitrogen,
        potassium: pbResp.potassium,
        phosphorus: pbResp.phosphorus,
        moisture: pbResp.moisture,
    };

    return json(nutrients);
}
