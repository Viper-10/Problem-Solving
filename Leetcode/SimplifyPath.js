var simplifyPath = function (path) {
  const PREVIOUS_DIRECTORY = "..";
  const pathSubstrings = path.split("/");

  let take = [];
  let output = "/";

  pathSubstrings.forEach((path, index) => {
    if (path === PREVIOUS_DIRECTORY) {
      if (take.length !== 0) {
        take.pop();
      }
    } else if (path !== "" && path !== ".") {
      take.push(path + "/");
    }
  });

  take.forEach((ele) => {
    output += ele;
  });

  return output.length > 1 ? output.substring(0, output.length - 1) : output;
};
