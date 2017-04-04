function ProgressBar(element, width)
{
	var red = 0;
	var green = 255;
	
	// Create Progress Bar inside container
	var bar = document.createElement("div");
	bar.style.width = "0%";
	bar.style.height = "100%";
	bar.className = "pBar";
	element.appendChild(bar);
	
	// Style container and progress bar
	element.className = "pBarContainer";
	element.style.width = width;
	
	this.setValue = function(percentage)
	{
		bar.style.width = percentage + "%";
		
		if(percentage < 50)
		{
			red = parseInt((percentage / 100.0) * 256, 10) * 2;
			green = 255;
		}
		else if(percentage >= 50)
		{
			red = 255;
			green = parseInt(256 - (percentage / 100.0) * 256, 10) * 2;
		}
		bar.style.backgroundColor = "rgb(" + red + ", " + green + ", 0)";
	}
}