const inquirer = require("inquirer");

inquirer
  .prompt([
    /* Pass your questions in here */
    {
      type: "confirm",
      name: "toBeDelivered",
      message: "Is this for delivery?",
      default: false,
    },
  ])
  .then((answers) => {
    // Use user feedback for... whatever!!
  })
  .catch((error) => {
    if (error.isTtyError) {
      // Prompt couldn't be rendered in the current environment
    } else {
      // Something else went wrong
    }
  });
