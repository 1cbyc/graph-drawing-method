document.addEventListener("DOMContentLoaded", () => {
    // Get canvas element and its context
    const canvas = document.getElementById("graphCanvas");
    const ctx = canvas.getContext("2d");
  
    // Prompt user for function parameters
    const slope = parseFloat(prompt("Enter the slope: "));
    const yIntercept = parseFloat(prompt("Enter the y-intercept: "));
  
    if (isNaN(slope) || isNaN(yIntercept)) {
      alert(
        "Invalid input. Please enter numeric values for slope and y-intercept."
      );
      return;
    }
  
    // Define the function
    const f = (x) => slope * x + yIntercept;
  
    // Set up the scale for the graph
    const scale = 20;
    const xOffset = canvas.width / 2;
    const yOffset = canvas.height / 2;
  
    // Draw x and y axes
    ctx.beginPath();
    ctx.moveTo(0, yOffset);
    ctx.lineTo(canvas.width, yOffset);
    ctx.stroke();
  
    ctx.beginPath();
    ctx.moveTo(xOffset, 0);
    ctx.lineTo(xOffset, canvas.height);
    ctx.stroke();
  
    // Plot the line graph
    ctx.beginPath();
    ctx.strokeStyle = "blue";
    ctx.lineWidth = 2;
    for (let x = -canvas.width / 2; x < canvas.width / 2; x += 0.1) {
      const y = f(x / scale) * scale;
      ctx.lineTo(x * scale + xOffset, -y + yOffset);
    }
    ctx.stroke();
  });
  