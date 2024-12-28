/** @type {import('tailwindcss').Config} */
module.exports = {
  content: [
    "./src/**/*.{js,jsx,ts,tsx}",
    "./src/app/**/*.jsx"
  ],
  presets: [require("nativewind/preset")],
  theme: {
    extend: {
      colors: {
        'text': '#040316',
        'background': '#e6e6e6',
        'primary': '#27625c',
        'secondary': '#6a9587',
        'accent': '#abd3bb',
       },       
    },
  },
  future: {
    hoverOnlyWhenSupported: true,
  },
  plugins: [],
};
