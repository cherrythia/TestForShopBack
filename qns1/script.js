
        function addFields(){
            // Number of inputs to create
            var T = document.getElementById("T").value;
            // Container <div> where dynamic content will be placed
	        var container = document.getElementById("container");

            if ( (T >= 1 ) && (T <=50) ) {

	            // Clear previous contents of the container
	            while (container.hasChildNodes()) {
	                container.removeChild(container.lastChild);
	            }
	            for (i=0;i<T ;i++){
	                // Append a node for N Text
	                container.appendChild(document.createTextNode("N" + (i+1)));
	                // Create an <input> element, set its type and name attributes
	                var input = document.createElement("input");
	                input.type = "text";
	                input.name = 'N[' + i + ']';										//name is in an array form!?
	                container.appendChild(input);

	                // Append a node for K Text
	                container.appendChild(document.createTextNode("K" + (i+1)));
	                // Create an <input> element, set its type and name attributes
	                var input = document.createElement("input");
	                input.type = "text";
	                input.name = 'K[' + i + ']';											//in array form!
	                container.appendChild(input);
	                // Append a line break 
	                container.appendChild(document.createElement("br"));

	            }
        	}
        	else{
        		alert('T value is out of range. Please re-enter it to be between 1<=T<=50');
        	}
        }
