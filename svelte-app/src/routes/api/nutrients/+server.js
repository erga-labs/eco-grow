import { pb } from "$lib/server/db/pocketbase";
import { json } from "@sveltejs/kit";

export async function GET(req) {
    console.log(req.request.url);
    const crop = new URL(req.request.url).searchParams.get("crop");
    console.log(crop);

    const pbResp = await pb.collection("mp_plant_info").getFirstListItem(`plant="${crop}"`);

    const nutrients = {
        nitrogen: pbResp.nitrogen.max,
        potassium: pbResp.potassium.max,
        phosphorus: pbResp.phosphorus.max,
        moisture: pbResp.moisture.max,
    };

    return json(nutrients);
}
