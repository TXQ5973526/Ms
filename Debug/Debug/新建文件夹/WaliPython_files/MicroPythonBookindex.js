var keyword = '';
var keywordNum = 0;
var firstStarStatus = true;
var userpeopleWebName = '';



var ajax_str = function() {
	
	peopleWebName = localStorage.peopleWebName;
	peopleWebPWD = localStorage.peopleWebPWD;

	var message = {
		"LINK": "p2c",
		"ISTR": "log",
		"CONT": "p",
		"peopleWebName": peopleWebName,
		"peopleWebPWD": peopleWebPWD,
	};
	
	$.ajax({

		type: "GET",
		url: "http://api.openioe.net/IOT/index.php",

		data: message,
		timeout: 5000,
		dataType: 'JSONP',
		jsonp: "callback", //传递给请求处理程序或页面的，用以获得jsonp回调函数名的参数名(默认为:callback)

		success: function(data) {

			if(data["INFO"] == "true") {
			userpeopleWebName = peopleWebName;
			}else
			{
				
			}

		},

		error: function() {

		}

	});

	return false;
}



//获取目录
var getQrcodeInfo = function() {

	var message = {
		"LINK": "qrcode",
		"ISTR": "inq",
		"CONT": "public-qrcode-d-page",
		"order": "true",
		"qrcodeIotPID": "gh941SnH4lvhQUOm",
		"PageNum": 1,
		"qrcodeType": "list",
		"MaxPerPage": 100
	};

	$.ajax({

		type: "GET",
		url: "https://api.openioe.net/IOT/index.php",
		data: message,

		dataType: 'JSONP',
		jsonp: "callback", //传递给请求处理程序或页面的，用以获得jsonp回调函数名的参数名(默认为:callback)

		success: function(data) {

			if(data["INFO"] == "true") {

				if(data["LIST"] != null) {
					$("#moudleClass").empty();
					for(var p in data["LIST"]) {
						var qrcodeDataId = data["LIST"][p].qrcodeDataId;
						var qrcodeInfoId = data["LIST"][p].qrcodeInfoId;
						var burnAllowed = data["LIST"][p].burnAllowed;
						var qrcodeType = data["LIST"][p].qrcodeType;
						var qrcodeInfo = data["LIST"][p].qrcodeInfo;
						var qrcodeTitle = data["LIST"][p].qrcodeTitle;
						var messageTime = data["LIST"][p].messageTime;
						var peopleWebName = data["LIST"][p].peopleWebName;

						if(keyword != '') {
							var re = '/' + keyword + '/g';
							qrcodeTitle = qrcodeTitle.replace(eval(re), '<span style="color: #ffffff; background: #00dd00;">' + keyword + '</span>');
						}

						if(p == 0) {
							$("#moudleClass").append('<li class="nb-titlebar-btn moudleClassLi active"><a>' + qrcodeTitle + '</a><ul class="nav" id="qrcodeInfoId' + qrcodeInfoId + '"></ul></li>');
						} else {
							$("#moudleClass").append('<li class="nb-titlebar-btn moudleClassLi "><a>' + qrcodeTitle + '</a><ul class="nav" id="qrcodeInfoId' + qrcodeInfoId + '" style="display:none ;" ></ul></li>');
						}

						getQrcodeDatasInfo(qrcodeInfoId);

					}

					$('.moudleClassLi').click(function(event) {
						event.stopPropagation();

						if($(this).hasClass('active')) {
							$(this).removeClass('active');
							$(this).find('.nav').hide();
						} else {
							$(this).addClass('active');
							$(this).find('.nav').show();
						}

					});

					$('.moudleClassLi .nav').click(function(e) {
						e.stopPropagation();
					});

				} else {

				}

			}

		},

		error: function() {}

	});
}
getQrcodeInfo();

//获取目录内容列表
var getQrcodeDatasInfo = function(qrcodeDataIdNum) {

	$("a.selected").removeClass('selected');
	var message = {
		"LINK": "qrcode",
		"ISTR": "inq",
		"CONT": "public-qrcode-ds-page",
		"order": "true",
		"qrcodeDataIdNum": qrcodeDataIdNum,
		"PageNum": 1,
		"MaxPerPage": 100
	};

	$.ajax({

		type: "GET",
		url: "https://api.openioe.net/IOT/index.php",
		data: message,

		dataType: 'JSONP',
		jsonp: "callback", //传递给请求处理程序或页面的，用以获得jsonp回调函数名的参数名(默认为:callback)

		success: function(data) {

			if(data["INFO"] == "true") {

				if(data["LIST"] != null) {

					for(var p in data["LIST"]) {

						var qrcodeInfoId = data["LIST"][p].qrcodeInfoId;

						var qrcodeDatasId = data["LIST"][p].qrcodeDatasId;

						var qrcodeInfo = data["LIST"][p].qrcodeInfo;
						var getqrcodeDataIdNum = data["LIST"][p].qrcodeDataIdNum;

						var qrcodeTitle = data["LIST"][p].qrcodeTitle;
						var qrcodeType = data["LIST"][p].qrcodeType;
						var messageTime = data["LIST"][p].messageTime;
						var peopleWebName = data["LIST"][p].peopleWebName;

						if(keyword != '') {
							var re = '/' + keyword + '/g';
							var temp = qrcodeTitle;
							qrcodeTitle = qrcodeTitle.replace(eval(re), '<span style="color: #ffffff; background: #00dd00;">' + keyword + '</span>');

							if(temp != qrcodeTitle) {
								keywordNum = keywordNum + 1;

								$('#keywordNum').html(keywordNum);
								$('#qrcodeInfoId' + qrcodeDataIdNum).show();
							}
						}

						$('#qrcodeInfoId' + qrcodeDataIdNum).append('<li class="nb-titlebar-btn moudleTitle"  id="moudleTitle' + qrcodeDatasId + '"><a onclick="getQrcodeDatassInfo(' + qrcodeInfoId + ',' + getqrcodeDataIdNum + ')"  >' + qrcodeTitle + '</a></li>');

						//$('#qrcodeInfoId' + qrcodeDataIdNum).append('<li class="dac-nav-item" onclick="getQrcodeDatassInfo(' + qrcodeInfoId + ',' + getqrcodeDataIdNum + ')" ><a class="dac-nav-link selected select' + qrcodeInfoId + '">' + qrcodeTitle + '</a></li>');

						if(firstStarStatus == true) {
							getQrcodeDatassInfo(qrcodeDatasId);
							firstStarStatus = false;
						}

					}

				} else {

				}

			}

		},

		error: function() {

		}

	});
}

//获取问题详情
var getQrcodeDatassInfo = function(qrcodeDatasId) {

	$('.moudleTitle').removeClass('active');
	$('#moudleTitle' + qrcodeDatasId).addClass('active');

	var message = {
		"LINK": "qrcode",
		"ISTR": "inq",
		"CONT": "public-qrcode-dss-page",
		"qrcodeDatasId": qrcodeDatasId,
		"PageNum": 1,
		"MaxPerPage": 1
	};

	$.ajax({

		type: "GET",
		url: "https://api.openioe.net/IOT/index.php",
		data: message,

		dataType: 'JSONP',
		jsonp: "callback", //传递给请求处理程序或页面的，用以获得jsonp回调函数名的参数名(默认为:callback)

		success: function(data) {

			if(data["INFO"] == "true") {

				if(data["LIST"] != null) {

					for(var p in data["LIST"]) {
						var qrcodeInfoId = data["LIST"][p].qrcodeInfoId;

						var qrcodeInfo = data["LIST"][p].qrcodeInfo;
						var qrcodeTitle = data["LIST"][p].qrcodeTitle;
						var qrcodeType = data["LIST"][p].qrcodeType;

						var messageTime = data["LIST"][p].messageTime;
						var peopleWebName = data["LIST"][p].peopleWebName;

						$("#test-editormd-view2").empty();
						$("#test-editormd-view2").append('<textarea id="append-test" style="display:none;"></textarea>');

						$("#append-test").val(qrcodeInfo);
						$("#pageInfo").html(peopleWebName + ' 编辑于 ' + messageTime + "&nbsp;");
						var dedd = "test-editormd-view2";
						testEditormdView2 = editormd.markdownToHTML(dedd, {
							htmlDecode: "style,script,iframe", // you can filter tags decode
							emoji: true,
							taskList: true,
							tex: true, // 默认不解析
							flowChart: true, // 默认不解析
							sequenceDiagram: true, // 默认不解析
						});

						$("#test-editormd-view2").show();

						$("#test-editormd-view2").find('a').click(function(event) {
							event.preventDefault();

							nw.Shell.openExternal($(this).attr("href"));
							return false;
						});

						$("html,body").animate({
							scrollTop: 0
						}, "fast");
					}

				} else {

				}

			}

		},

		error: function() {
			//getQrcodeInfo();
		}

	});
}

$('#search').keydown(function(e) {
	if(e.keyCode == 13) {
		keywordNum = 0;
		keyword = $('#search').val();
		getQrcodeInfo();
	}
});

/*
 * 名称：赛灵开源社区连接
 * 输入：
 * 输出：
 * 描述：
 */
$("#CelerStar").click(function() {
		var nbOption = {
			width: 500,
			height: 400,
			min_width: 500,
			min_height: 400,
			max_width: 500,
			max_height: 400,
			resizable: false,
			frame: false,
			show: true
		};
		nw.Window.open('APP/OpenIOE-CORE-CARD-8051-BOOK/login.html', nbOption, function(new_win) {
			// 监听新窗口的焦点事件
			new_win.on('focus', function() {
				console.log('New window is focused');
			});
		});


});

$("#openioe").click(function() {
	nw.Shell.openExternal('http://www.openioe.net/');
});

$("#addNewFileBtn").click(function() {
	if(userpeopleWebName != null) {
		var nbOption = {
			width: 800,
			height: 600,
			min_width: 800,
			min_height: 600,
			max_width: 0,
			max_height: 0,
			resizable: true,
			frame: false,
			show: true
		};

		nw.Window.open('APP/OpenIOE-CORE-CARD-8051-BOOK/MicroPythonBookindex.html', nbOption, function(new_win) {
			// 监听新窗口的焦点事件
			new_win.on('focus', function() {
				console.log('New window is focused');
			});
		});


	} else {
		

		
		var nbOption = {
			width: 500,
			height: 400,
			min_width: 500,
			min_height: 400,
			max_width: 500,
			max_height: 400,
			resizable: false,
			frame: false,
			show: true
		};

		nw.Window.open('APP/OpenIOE-MicroPythonBook/login.html', nbOption, function(new_win) {
			// 监听新窗口的焦点事件
			new_win.on('focus', function() {
				console.log('New window is focused');
			});
		});

	
	
	}
});

var appIotAID = "00OpenIOEMPYBOOK";
var appVersionNowNum = 100;
var appUpdateUrl = 'http://www.celerstar.com/';

$("#download").click(function() {
	nw.Shell.openExternal(appUpdateUrl);
})

var inqappInfo = function() {

	var message = {
		"LINK": "app",
		"ISTR": "inq",
		"CONT": "appInfo",
		"appIotAID": appIotAID,
	};

	$.ajax({

		type: "GET",
		url: "https://api.openioe.net/APP/index.php",

		data: message,
		timeout: 3000,
		dataType: 'JSONP',
		jsonp: "callback", //传递给请求处理程序或页面的，用以获得jsonp回调函数名的参数名(默认为:callback)

		success: function(data) {

			if(data["INFO"] == "true") {

				var appUpdateEnable = data["NOTE"]["appUpdateEnable"];
				appUpdateUrl = data["NOTE"]["appUpdateUrl"];
				var appUpdateInfo = data["NOTE"]["appUpdateInfo"];
				var appVersionNum = Number(data["NOTE"]["appVersionNum"]);

				if(appUpdateEnable == "ON" && appVersionNum > appVersionNowNum) {
					//$('#updateInfo').html(appUpdateInfo);
					//$('#updateBox').modal('show');

				}
			} else {

			}

		},

		error: function() {
			$('#netErrorBox').modal('show');
		}

	});

	return false;
}

inqappInfo();

var upAppViewCount = function() {

	var message = {
		"LINK": "app",
		"ISTR": "rev",
		"CONT": "appViewCount",
		"appIotAID": appIotAID,
	};

	$.ajax({

		type: "GET",
		url: "http://api.openioe.net/APP/index.php",

		data: message,
		timeout: 3000,
		dataType: 'JSONP',
		jsonp: "callback",

		success: function(data) {

			if(data["INFO"] == "true") {

			} else {}

		},

		error: function() {}

	});

	return false;
}

upAppViewCount();

var inquser = function() {

	var message = {
		"LINK": "p",
		"ISTR": "inq",
		"CONT": "userinfo",
	};

	$.ajax({

		type: "GET",
		url: "http://api.openioe.net/IOT/index.php",

		data: message,

		dataType: 'JSONP',
		jsonp: "callback", //传递给请求处理程序或页面的，用以获得jsonp回调函数名的参数名(默认为:callback)

		success: function(data) {

			if(data["INFO"] == "true") {

				userpeopleWebName = data["LIST"]["peopleWebName"];

			}else
			{
				ajax_str();
			}

		},

		error: function() {

		}

	});

	return false;
}

inquser();

localStorage.mpybook = true;

var win = nw.Window.get();

win.on('close', function() {
  this.hide(); // Pretend to be closed already
  localStorage.mpybook = false;
  this.close(true); // then close it forcely
});