$(function() {
// css js styles
	$(".slideable").hide();
   
	$(".slideable").before(function() {
		return "<div class='slidereveal' opened='false'><a href='#"+this.id+"'>"+this.id+"</a></div>";
	});
   
	$(".slidereveal").click(function(event) {
   		var revealed = $(this).next(".slideable") ;
		if (!revealed.is(":visible")) {
		  $(this).attr("opened", "true");
		} else {
		  $(this).attr("opened", "false");
		}
		revealed.slideToggle();
		event.preventDefault();
	});

// 	$(".selectlang").each(function() {
// 		$(this).children("a").each(function() {
// 			if ($(this).text() == document.documentElement.lang) {
// 				$(this).attr("class", "currlang");
// 			}
// 		});
// 	});
	
    $(window).on('load', function() {
      // Look for svg objects and set their size to the bounding box of the svg document
      // Handle width and height in percents with value > 1000 as percentages relative
      // to the natural size of the svg document (instead of the HTML page size)
      $("object[type='image/svg+xml']").each(function() {
        var eltWidth = $(this).attr("width");
        var eltHeight = $(this).attr("height");
        var targetWidth = 0;
        var targetHeight = 0;
        // The SVG element is the documentElement of the contentDocument of the object
        var svgDocument = $(this).get(0).contentDocument;
        if (svgDocument == null) {
          console.log("# Error: could not get document of " + $(this));
          return;
        }
        var svgElement = svgDocument.documentElement;
        if (svgElement.hasAttribute("viewBox")) {
          var vbox = svgElement.getAttribute("viewBox");
          var elems = vbox.split(" ");
          if (elems.length == 4) {
            targetWidth = parseFloat(elems[2]);
            targetHeight = parseFloat(elems[3]);
          }
        }
        if (targetWidth == 0 || targetHeight == 0) {
          var bbox = svgElement.getBBox();
          targetWidth = bbox.width;
          targetHeight = bbox.height;
        }
        if (eltWidth == null && eltHeight == null) {
          $(this).attr("width", targetWidth);
          $(this).attr("height", targetHeight);
        } else {
          if (eltWidth != null) {
            if (eltWidth.match(/[0-9]+%/)) {
              var val = parseFloat(eltWidth.substring(0, eltWidth.length));
              if (val > 1000) {
                val = (val - 1000) / 100;
                $(this).attr("width", targetWidth * val);
              }
            }
          }
          if (eltHeight != null) {
            if (eltHeight.match(/[0-9]+%/)) {
              var val = parseFloat(eltHeight.substring(0, eltHeight.length));
              if (val > 1000) {
                val = (val - 1000) / 100;
                $(this).attr("height", targetHeight * val);
              }
            }
          }
        }
      });
    });
        
    if ($("span[class=buildtoc]").length > 0) {
        var navtitle = $("span[class=buildtoc]").first().contents();
        var menu = $("<ul>");
        var currentmenu = menu;
        var previouslevel = 1;
        var showmenu = false;
        $(":header[id]").each(function() {
          var level = parseInt($(this).prop("tagName").substring(1));
          if (level > previouslevel) {
            while (previouslevel < level) {
              var newitem = $("<p>");
              currentmenu.append(newitem);
              var newmenu = $("<ul>");
              newitem.append(newmenu);
              currentmenu = newmenu;
              previouslevel++;
            }
          } else if (level < previouslevel) {
            while (level < previouslevel) {
              currentmenu = currentmenu.parent().parent();
              previouslevel--;
            }
          }
          var link = $("<a>", {href : "#" + $(this).attr("id")});
          var text = $(this).text();
          var toctext = $(this).children("span[class=toc]").text();
          if (toctext != "") {
            text = toctext;
          }
          link.text(text);
          currentmenu.append($("<li>").append(link));
          showmenu = true;
        });
        if (showmenu) {
          var navmenudiv = $("<div>", {id : "navmenu"});
          var navtitlediv = $("<div>", {class : "navmenutitle"});
          var navmenucontents = $("<div>", {id : "navmenucontents"});
          navmenucontents.append(menu);
          navtitlediv.append(navtitle);
          navmenudiv.append(navtitlediv);
          navmenudiv.append(navmenucontents);
          navtitlediv.bind("click", function() {
            $(this).parent().children("[id=navmenucontents]").slideToggle();
          });
        }
        $("body").append(navmenudiv);
    }
});
