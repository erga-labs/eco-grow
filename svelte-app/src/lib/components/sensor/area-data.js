const csvNortheast = `Day, N
  12hr,29.662053
  11hr,34.427091
  10hr,35.976777
  9hr,39.477986
  8hr,44.677819
  7hr,49.040703
  6hr,49.135283
  5hr,50.809229
  4hr,53.594378
  2hr,55.317240
  1hr,57.609148`;

const csvMidwest = `Year,P
  12hr,34.019792
  11hr,38.594100
  10hr,40.143332
  9hr,44.460762
  8hr,51.619139
  7hr,56.571663
  6hr,58.865670
  5hr,59.668632
  4hr,64.392776
  2hr,66.927001
  1hr,68.985454`;

const csvSouth = `Year,K
  12hr,33.125803
  11hr,37.857633
  10hr,41.665901
  9hr,47.7hr88
  8hr,54.973113
  7hr,62.795367
  6hr,75.372362
  5hr,85.445930
  4hr,100.236820
  2hr,114.555744
  1hr,126.266107`;

const csvWest = `Year,Moisture
  12hr,9.213920
  11hr,12.323836
  10hr,14.379119
  9hr,20.189962
  8hr,28.053104
  7hr,34.804193
  6hr,43.172490
  5hr,52.786082
  4hr,63.197932
  2hr,71.945553
  1hr,78.588572`;

function csvConvert(csv) {
    return csv
        .split("\n")
        .slice(1)
        .map((str) => {
            const [date, population] = str.split(",").map((el) => (el > 1900 ? new Date(el, 0) : parseFloat(el)));
            return { date, population };
        });
}
const northeast = csvConvert(csvNortheast);
const midwest = csvConvert(csvMidwest);
const south = csvConvert(csvSouth);
const west = csvConvert(csvWest);

export default [
    {
        id: "N",
        data: northeast,
    },
    {
        id: "P",
        data: midwest,
    },
    {
        id: "K",
        data: south,
    },
    {
        id: "Moisture",
        data: west,
    },
];
