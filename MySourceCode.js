// There's something wrong with both of these array initializations
var words = "Lane", "Community", "College", "Computer", "Science", "Department";
var sentence=concatWords(words);
alert(sentence);
var messages = "There's", "Three", "Errors", "Can", "You", "Find", "Them?";
alertBox(messages);

function concatWords(words) {
	var i, len, text;
	for (i = 0, len = words.length, text = ""; i < len; i++) {
		// There's something wrong with this concatenation
		text =+ words[i] + " ";
	}
	return text;
}

function alertBox(messages) {
	var i = 0;
	var len = messages.length;
	//There's something missing inside this loop
	for (; i < len; ) {
		alert(messages[i])
		i++;
	}
}

