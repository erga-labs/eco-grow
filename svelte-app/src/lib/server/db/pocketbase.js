import { POCKETBASE_URL } from '$env/static/private';
import Pocketbase from 'Pocketbase';

const pb = new Pocketbase(POCKETBASE_URL);

export { pb };