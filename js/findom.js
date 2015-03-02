// script to dynamically change the height is proportional to the width of the screen
    $(function(){
        $('.big-height').height($('.fiftyminus').width()/0.71);
        $(window).resize(function(){
            $('.big-height').height($('.fiftyminus').width()/0.71);
        });
    });      
    
    $(function(){
        $('.height').height($('.fifty').width()/2.85);
        $(window).resize(function(){
            $('.height').height($('.fifty').width()/2.85);
        });
    });     
            
    $(function(){
        $('.big-height').height($('.fiftyplus').width()/2.13);
        $(window).resize(function(){
            $('.big-height').height($('.fiftyplus').width()/2.13);
        });
    });
    
    $(function(){
        $('.double-big-height').height($('.fiftyplus').width()/1.42);
        $(window).resize(function(){
            $('.double-big-height').height($('.fiftyplus').width()/1.42);
        });
    }); 
            
    $(function(){
        $('.height').height($('.fiftyplus').width()/4.27);
        $(window).resize(function(){
            $('.height').height($('.fiftyplus').width()/4.27);
        });
    }); 

    $(function(){
        $('.double-big-height').height($('.fiftyminus').width()/0.473);
        $(window).resize(function(){
            $('.double-big-height').height($('.fiftyminus').width()/0.473);
        });
    }); 
        
    $(function(){
        $('.big').height($('.plusplus').width()/2.84);
        $(window).resize(function(){
            $('.big').height($('.plusplus').width()/2.84);
        });
    });

        function ArrowMeter(){
            var height = $('.big-height').height();
            var result = height / 2.7;
            $('.fotorama__arr--prev').css('top', result);
            $('.fotorama__arr--next').css('top', result);
            $('.prev').css('top', result);
            $('.next').css('top', result);
        };

    $(function(){
        ArrowMeter();
        $(window).resize(function(){
            ArrowMeter();
        });
    }); 




 // jQuery for page scrolling feature - requires jQuery Easing plugin
 $(function() {
    $('.page-scroll a').bind('click', function(event) {
        var $anchor = $(this);
        $('html, body').stop().animate({
            scrollTop: $($anchor.attr('href')).offset().top
        }, 1500, 'easeInOutExpo');
        event.preventDefault();
    });
});


//  scroll up
 $(document).ready(function () {

    $(window).scroll(function () {
        if ($(this).scrollTop() > 100) {
            $('.scrollup').fadeIn();
        } else {
            $('.scrollup').fadeOut();
        }
    });

    $('.scrollup').click(function () {
        $("html, body").animate({
            scrollTop: 0
        }, 600);
        return false;
    });
});

 
//  sticky menu
    $(window).load(function(){
      $("#header").sticky({ topSpacing: 0, className: 'sticky', wrapperClassName: 'my-wrapper' });
    });


//  map-filter select
    $(function() {
        $('#map-filter').change(function() {
            console.log($(this).val());
        }).multipleSelect({
            width: '100%'
        });
    });

//  mini-map-filter select
    $(function() {
        $('#mini-map-filter').change(function() {
            console.log($(this).val());
        }).multipleSelect({
            width: '100%',
			placeholder:'ОТОБРАЖАТЬ НА КАРТЕ',
        });
    });



//  date multiple select
    $(function() {
        $('#date').change(function() {
            console.log($(this).val());
        }).multipleSelect({
            placeholder: '',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
        });
    });


//  wall type multiple select
    $(function() {
        $('#wall_type').change(function() {
            console.log($(this).val());
        }).multipleSelect({
            placeholder: '',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
        });
    });


//  category type multiple select
    $(function() {
        $('#cat').change(function() {
            console.log($(this).val());
        }).multipleSelect({
            placeholder: '',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
        });
    });


//  balkon type multiple select
    $(function() {
        $('#balkon').change(function() {
            console.log($(this).val());
        }).multipleSelect({
            placeholder: '',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
        });
    });


//  adress type multiple select
    $(function() {
        $('#adds').change(function() {
            console.log($(this).val());
        }).multipleSelect({
            placeholder: 'Адрес дома',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
        });
    });


//  room type multiple select
    $(function() {
        $('#room').change(function() {
            console.log($(this).val());
        }).multipleSelect({
            placeholder: 'Комнаты',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
        });
    });


//  section type multiple select
    $(function() {
        $('#fsection').change(function() {
            console.log($(this).val());
        }).multipleSelect({
            placeholder: 'Секция',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
        });
    });

//  section type multiple select
    $(function() {
        $('#ffloor').change(function() {
            console.log($(this).val());
        }).multipleSelect({
            placeholder: 'Этаж',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
        });
    });


//  adress-city type multiple select
    $(function() {
        $('#adds-city').change(function() {
            console.log($(this).val());
        }).multipleSelect({
            placeholder: 'Адрес дома',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
        });
    });




//  section city type multiple select
    $(function() {
        $('#fsection-city').change(function() {
            console.log($(this).val());
        }).multipleSelect({
            placeholder: 'Секция',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
        });
    });

//  ffloor-city type multiple select
    $(function() {
        $('#ffloor-city').change(function() {
            console.log($(this).val());
        }).multipleSelect({
            placeholder: 'Этаж',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
        });
    });

	//apartment buttons

        $(document).ready(function(){
       $("#comparisonh").hover(function(){
           $(this).css("opacity","1");
          $("#comparison").css("color","#000");
       });
    });
    $(document).ready(function(){
       $("#comparisonh").mouseout(function(){
         $(this).css("opacity","0");
          $("#comparison").css("color","#999");
       });
    });
        
    $(document).ready(function(){
       $("#bankh").hover(function(){
           $(this).css("opacity","1");
          $("#bank").css("color","#000");
       });
    });
    $(document).ready(function(){
       $("#bankh").mouseout(function(){
         $(this).css("opacity","0");
          $("#bank").css("color","#999");
       });
    });
        
    $(document).ready(function(){
       $("#documentsh").hover(function(){
           $(this).css("opacity","1");
          $("#documents").css("color","#000");
       });
    });
    $(document).ready(function(){
       $("#documentsh").mouseout(function(){
         $(this).css("opacity","0");
          $("#documents").css("opacity","#999");
       });
    });

    $(document).ready(function(){
       $("#callh").hover(function(){
           $(this).css("opacity","1");
          $("#call").css("color","#000");
       });
    });
    $(document).ready(function(){
       $("#callh").mouseout(function(){
         $(this).css("opacity","0");
          $("#call").css("opacity","#999");
       });
    });





// map
ymaps.ready(init);

function init () {
    var myMap = new ymaps.Map("map", {
            center: [55.76, 37.64],
            zoom: 12
        }),

		
		 myPlacemark4 = new ymaps.Placemark([55.77, 37.65], {
            // Свойства.
            hintContent: ''
        }, {
            // Опции.
            // Своё изображение иконки метки.
            iconImageHref: '/images/tag.png',
            // Размеры метки.
            iconImageSize: [45, 70],
            // Смещение левого верхнего угла иконки относительно
            // её "ножки" (точки привязки).
            iconImageOffset: [-3, -42]
        });
	
		myPlacemark1 = new ymaps.Placemark([55.8, 37.6], {
            // Свойства.
            hintContent: ''
        }, {
            // Опции.
            // Своё изображение иконки метки.
            iconImageHref: '/images/tag.png',
            // Размеры метки.
            iconImageSize: [45, 70],
            // Смещение левого верхнего угла иконки относительно
            // её "ножки" (точки привязки).
            iconImageOffset: [-3, -42]
        });
	

        myPlacemark2 = new ymaps.Placemark([55.76, 37.56], {
            // Свойства.
            hintContent: ''
        }, {
            // Опции.
            // Своё изображение иконки метки.
            iconImageHref: '/images/tag.png',
            // Размеры метки.
            iconImageSize: [45, 70],
            // Смещение левого верхнего угла иконки относительно
            // её "ножки" (точки привязки).
            iconImageOffset: [-3, -42]
        });

    // Добавляем все метки на карту.
    myMap.geoObjects
        .add(myPlacemark4)
        .add(myPlacemark2)
        .add(myPlacemark1);
}


    // meters slider
    $(function () {
        $("#meters").ionRangeSlider({
            hide_min_max: true,
            keyboard: true,
            min: 0,
            max: 200,
            postfix: " м<sup>2</sup>",
            from: 30,
            to: 150,
            type: 'double',
            step: 1,
            grid: true
        });
    });


    // meter-price slider
    $(function () {
        $("#meter-price").ionRangeSlider({
            hide_min_max: true,
            keyboard: true,
            min: 40,
            max: 100,
            postfix: " т.р.",
            from: 55,
            to: 85,
            type: 'double',
            step: 1,
            grid: true
        });
    });


    // flat-price slider
    $(function () {
        $("#flat-price").ionRangeSlider({
            hide_min_max: true,
            keyboard: true,
            min: 0.5,
            max: 5,
            postfix: " млн.р.",
            from: 1.6,
            to: 4,
            type: 'double',
            step: 0.2,
            grid: true
        });
    });


    //plan-zk 
    $(document).ready(function() {
        $(".a-dom").click(function(){
            $('#block1').hide();
            $('#block2').show();
        });

        $(".a-section").click(function(){
            $('#block2').hide();
            $('#block3').show();
        });

        $(".block1").click(function(){
            $('#block3').hide();
            $('#block2').hide();
            $('#block1').show();
        });

        $(".block2").click(function(){
            $('#block1').hide();
            $('#block3').hide();
            $('#block2').show();
        });
    });       


    // чек бокс для модалки
    $(document).ready(function(){
        // проверяем, какие чекбоксы активны и меняем сласс для родительского дива

        $('.modal_checkbox').each(function(){
            var checkbox = $(this).find('input[type=checkbox]');
            if(checkbox.prop("checked")) $(this).addClass("check_active");
        });

        // при клике по диву, делаем проверку
        $('.modal_checkbox').click(function(){
            var checkbox = $(this).find('input[type=checkbox]');
            // если чекбокс был активен
            if(checkbox.prop("checked")){
                // снимаем класс с родительского дива
                $(this).removeClass("check_active_modal");
                // и снимаем галочку с чекбокса
                checkbox.prop("checked", false);
            // если чекбокс не был активен
            }else{
                // добавляем класс родительскому диву
                $(this).addClass("check_active_modal");
                // ставим галочку в чекбоксе
                checkbox.prop("checked", true);
            }
        });
    });


    // чек бокс для парковки
    $(document).ready(function(){
        // проверяем, какие чекбоксы активны и меняем сласс для родительского дива

        $('.decor_checkbox').each(function(){
            var checkbox = $(this).find('input[type=checkbox]');
            if(checkbox.prop("checked")) $(this).addClass("check_active");
        });

        // при клике по диву, делаем проверку
        $('.decor_checkbox').click(function(){
            var checkbox = $(this).find('input[type=checkbox]');
            // если чекбокс был активен
            if(checkbox.prop("checked")){
                // снимаем класс с родительского дива
                $(this).removeClass("check_active");
                // и снимаем галочку с чекбокса
                checkbox.prop("checked", false);
            // если чекбокс не был активен
            }else{
                // добавляем класс родительскому диву
                $(this).addClass("check_active");
                // ставим галочку в чекбоксе
                checkbox.prop("checked", true);
            }
        });
    });


	//apartment buttons

        $(document).ready(function(){
       $("#comparisonh").hover(function(){
           $(this).css("opacity","1");
          $("#comparison").css("color","#000");
       });
    });
    $(document).ready(function(){
       $("#comparisonh").mouseout(function(){
         $(this).css("opacity","0");
          $("#comparison").css("color","#999");
       });
    });
        
    $(document).ready(function(){
       $("#bankh").hover(function(){
           $(this).css("opacity","1");
          $("#bank").css("color","#000");
       });
    });
    $(document).ready(function(){
       $("#bankh").mouseout(function(){
         $(this).css("opacity","0");
          $("#bank").css("color","#999");
       });
    });
        
    $(document).ready(function(){
       $("#documentsh").hover(function(){
           $(this).css("opacity","1");
          $("#documents").css("color","#000");
       });
    });
    $(document).ready(function(){
       $("#documentsh").mouseout(function(){
         $(this).css("opacity","0");
          $("#documents").css("color","#999");
       });
    });

    $(document).ready(function(){
       $("#callh").hover(function(){
           $(this).css("opacity","1");
          $("#call").css("color","#000");
       });
    });
    $(document).ready(function(){
       $("#callh").mouseout(function(){
         $(this).css("opacity","0");
          $("#call").css("color","#999");
       });
    });




