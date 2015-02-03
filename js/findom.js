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


// map
ymaps.ready(init);

function init () {
    var myMap = new ymaps.Map("map", {
            center: [55.76, 37.64],
            zoom: 12
        }),

        // Создаем геообъект с типом геометрии "Точка".
        myGeoObject = new ymaps.GeoObject({
            // Описание геометрии.
            geometry: {
                type: "Point",
                coordinates: [55.8, 37.8]
            },
            // Свойства.
            properties: {
                // Контент метки.
        
                balloonContent: 'Меня можно перемещать'
            }
        }, {
            // Опции.
            // Иконка метки будет растягиваться под размер ее содержимого.
            preset: 'twirl#redStretchyIcon',
            // Метку можно перемещать.
            draggable: true
        }),

        // Создаем метку с помощью вспомогательного класса.
        myPlacemark1 = new ymaps.Placemark([55.8, 37.6], {
            // Свойства.
            // Содержимое иконки, балуна и хинта.
            iconContent: '1',
            balloonContent: 'Балун',
            hintContent: 'Стандартный значок метки'
        }, {
            // Опции.
            // Стандартная фиолетовая иконка.
            preset: 'twirl#violetIcon'
        }),

        myPlacemark2 = new ymaps.Placemark([55.76, 37.56], {
            // Свойства.
            hintContent: 'Собственный значок метки'
        }, {
            // Опции.
            // Своё изображение иконки метки.
            iconImageHref: '/images/minihome.png',
            // Размеры метки.
            iconImageSize: [30, 42],
            // Смещение левого верхнего угла иконки относительно
            // её "ножки" (точки привязки).
            iconImageOffset: [-3, -42]
        });

    // Добавляем все метки на карту.
    myMap.geoObjects
        .add(myPlacemark1)
        .add(myPlacemark2)
        .add(myGeoObject);
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


    //mini table no-sort
    $(document).ready(function() {
        $('#complex').dataTable( {
            "paging": false,
            "info": false,
            "columnDefs": [ {
                "targets": [ 0,1,2,8],
                "orderable": false,
            } ]
        } );
    } );
	


