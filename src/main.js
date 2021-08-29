// external libs import
const inquirer = require("inquirer");
const fs = require("fs");

// internal lib import
const buildConfig = require("./buildConfig");

const exitingConfig = fs.existsSync(".togepi.json");

if (exitingConfig) {
  inquirer
    .prompt([
      /* Pass your questions in here */
      {
        type: "confirm",
        name: "overwrite",
        message:
          "togepi-config.json already exists! Would you like to overwrite it?",
        default: false,
      },
    ])
    .then((answers) => {
      if (answers.overwite) {
        // TODO
        buildConfig();
      } else console.log("Goodbye! 👋");
    });
} else {
  buildConfig();
}
