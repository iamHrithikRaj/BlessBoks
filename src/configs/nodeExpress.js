const inquirer = require("inquirer");

const baseConfig = {
  name: "node-server-express-example",
  version: 2,
  builds: [
    {
      src: "src/index.js",
      use: "@now/node-server",
    },
  ],
  routes: [{ src: "/.*", dest: "src/index.js" }],
};

async function nodeExpress(config) {
  let mainFile = "src/index.js";
  try {
    // eslint-disable-next-line
    const packageJSON = require(`${process.cwd()}/package.json`);
    mainFile = packageJSON.main;
    // eslint-disable-next-line
  } catch (error) {}

  const answers = await inquirer.prompt([
    /* Pass your questions in here */
    {
      type: "text",
      name: "main",
      message: "What is the path to your express entry point?",
      default: mainFile,
    },
  ]);
  console.log(answers);
  return {
    ...config,
    ...baseConfig,
  };
}

module.exports = nodeExpress;
