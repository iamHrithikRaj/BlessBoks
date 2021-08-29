const path = require("path");
const inquirer = require("inquirer");
const nodeExpress = require("./configs/nodeExpress");

const buildConfig = async () => {
  // base config
  let config = {
    version: 2,
  };

  const answers = await inquirer.prompt([
    /* Pass your questions in here */
    {
      type: "text",
      name: "name",
      message: "What is the name of the project?",
      default: path.basename(process.cwd()),
    },
    {
      type: "list",
      name: "type",
      message: "What type of project?",
      choices: [
        "node-express",
        "static",
        "react",
        "vue",
        "static-build",
        "lambda",
      ],
    },
  ]);

  config.name = answers.name;
  switch (answers.type) {
    case "node-express":
      config = await nodeExpress(config);
      break;
    default:
      console.log("An unknow error occured!");
  }
  console.log(config);
};

module.exports = buildConfig;
