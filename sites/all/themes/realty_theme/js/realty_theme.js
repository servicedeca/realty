(function ($) {

 Drupal.behaviors.realtyMultyselect = {
   attach: $(function() {
     if(Drupal.settings.id) {
       $("body").attr("id","index");
     }
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
        // console.log($(this).val());
       }).multipleSelect({
         placeholder: '',
         selectAllText: 'Отметить все',
         allSelected: 'Все'
       });
     });


//  wall type multiple select
     $(function() {
       $('#wall_type').change(function() {
        // console.log($(this).val());
       }).multipleSelect({
         placeholder: '',
         selectAllText: 'Отметить все',
         allSelected: 'Все'
       });
     });


//  category type multiple select
     $(function() {
       $('#cat').change(function() {
        // console.log($(this).val());
       }).multipleSelect({
         placeholder: '',
         selectAllText: 'Отметить все',
         allSelected: 'Все'
       });
     });


//  balkon type multiple select
     $(function() {
       $('#balkon').change(function() {
       //  console.log($(this).val());
       }).multipleSelect({
         placeholder: '',
         selectAllText: 'Отметить все',
         allSelected: 'Все'
       });
     });
     $(".sq").ionRangeSlider({
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
     $(".price").ionRangeSlider({
       hide_min_max: true,
       keyboard: true,
       min: 40,
       max: 100,
       postfix: " т.р.",
       from: 55,
       to: 85,
       type: 'double',
       step: 1,
       grid: true,
       hasGrid: true

     });
     $(".coast").ionRangeSlider({
       hide_min_max: true,
       keyboard: true,
       min: 0.5,
       max: 5,
       postfix: " млн.р.",
       from: 1.6,
       to: 4,
       type: 'double',
       step: 0.2,
       grid: true,
       hasGrid: true
     });


     $('.CheckboxArea').click(function () {
       //console.log(select.text());
      if ($(this).prop("checked") == true ) {
        $('#area option[value='+$(this).val()+']').attr('selected', 'selected');
        var select = $('#area option:selected');
        $('.search-input-area').val(select.text());
      }
       else{
        $('#area option[value='+$(this).val()+']').attr('selected', false);
        var select = $('#area option:selected');
        $('.search-input-area').val(select.text());
      }
       $('.search-input-area').val(select.text());
     });

     $('.CheckboxMapArea').click(function () {
       var select = $('select[id="area-map"]');
       $(this).prop("checked") == true ? $('#area-map option[value='+$(this).val()+']').attr('selected', 'selected') :
         $('#area-map option[value='+$(this).val()+']').attr('selected', false);
     });

     $('.CheckboxArea').click(function() {
       var select = $('#area option:selected');
       console.log(select.text());
       $('.search-input-area').val(select.text());
     });

     $('.CheckboxRoom').click(function () {
       var select = $('select[id="room"]');
       $(this).prop("checked") == true ? $('#room option[value='+$(this).val()+']').attr('selected', 'selected') :
         $('#room option[value='+$(this).val()+']').attr('selected', false);
     });

     $('.CheckboxMetro').click(function () {
       var select = $('select[id="metro"]');
       $(this).prop("checked") == true ? $('#metro option[value='+$(this).val()+']').attr('selected', 'selected') :
         $('#metro option[value='+$(this).val()+']').attr('selected', false);
     });

     $('.CheckboxDeveloper').click(function () {
       var select = $('select[id="developer"]');
       if ($(this).prop("checked") == true) {
         $('#developer option[value='+$(this).val()+']').attr('selected', 'selected');
         console.log( $("#developer").val());
         complex_select($("#developer").val());
       }
       else {
         $('#developer option[value='+$(this).val()+']').attr('selected', false);
       }
     });

     $('.CheckboxComplex').click(function () {
       var select = $('select[id="complex"]');
       $(this).prop("checked") == true ? $('#complex option[value='+$(this).val()+']').attr('selected', 'selected') :
         $('#complex option[value='+$(this).val()+']').attr('selected', false);
     });

     function complex_select(devid){
       var city = $('input[name="city"]');
       $.ajax({
         url: '/get_developer_complex',
         type: 'POST',
         data: {
           developer: devid,
           city: city.val()
         },
         success: function(response) {
           var object = jQuery.parseJSON(response);
           console.log(response);
           $('.complexes-lis').html('');
           $('#complex').html('');
           if (object != null) {
             $('.complexes-lis').html(object.modal);
             $('#complex').html(object.select);
           }
         },
         error: function(response) {
           alert('false');
         }
       });
     }

     // действия после полной загрузки страницы
       // проверяем, какие чекбоксы активны и меняем сласс для родительского дива
       $('.decor_checkbox').each(function(){
         var checkbox = $('#parking');
         if(checkbox.prop("checked")) $(this).addClass("check_active");
       });

     // при клике по диву, делаем проверку
     $('.decor_checkbox').click(function() {
       var checkbox = $('#parking');
       // если чекбокс был активен
       if(checkbox.prop("checked")){
         // снимаем класс с родительского дива
         $(this).removeClass("check_active");
         // и снимаем галочку с чекбокса
         checkbox.prop("checked", false);
         // если чекбокс не был активен
         checkbox.val(0);
       }else{
         // добавляем класс родительскому диву
         $(this).addClass("check_active");
         // ставим галочку в чекбоксе
         checkbox.prop("checked", true);
         checkbox.val(1);
       }
     });
   })
  };



  Drupal.behaviors.realtySearchMap = {
    attach: $(function () {
      $("#map-filter").change(function () {
        var select = $('select[id="edit-field-category-value"]');
        select.val($(this).val());
        $('#edit-submit-map').trigger('click');
      });

      $(".CheckboxMapArea").change(function () {
        var select = $('select[id="edit-field-area-tid"]');
        select.val($(this).val());
        $('#edit-submit-map').trigger('click');
      });
    })
  };

  Drupal.behaviors.realtyGetIdApartment = {
    attach: $(function () {
      $("#get-id-apartment").click(function () {

        var nid = $(this).data('node-id');
        $.ajax({
          url: '/get_id_apartment',
          type: 'POST',
          data: {
            nid: nid
          },
          success: function(response) {

          },
          error: function(response) {
            alert('false');
          }
        });
      });

      $("#apartment-comparison").click(function () {

        var nid = $(this).data('node-id');
        $.ajax({
          url: '/apartment_comparison',
          type: 'POST',
          data: {
            nid: nid
          },
          success: function(response) {
            alert('Добавленнно');
          },
          error: function(response) {
            alert('false');
          }
        });
      });

    })
  };

  Drupal.behaviors.realtyCheckAdminMap = {
    attach: $(function () {
      var realtyAdmin = function() {
        var realty_admin
        $.ajax({
          url: '/check_admin_map',
          type: 'POST',
          async: false,
          data: {
          },
          success: function(response) {
            // alert(response);
            if (response == 1) {
              realty_admin = 1;
            }
            else {
              realty_admin = 0;
            }
          },
          error: function(response) {
            alert('false');
          }
        });
        return realty_admin;
      };
    })
  };


  Drupal.behaviors.realtyDynamicallyChange = {
    attach: $(function() {
     /* if(!$(".big-height").length) {
        $('.big-height').height($('.fiftyminus').width()/0.71);
      }*/
      $('.big-height').height($('.fiftyminus').width()/0.71);
      $('.height').height($('.fifty').width()/2.85);
      $('.big-height').height($('.fiftyplus').width()/2.13);
      $('.double-big-height').height($('.fiftyplus').width()/1.42);
      $('.double-big-height').height($('.fiftyplus').width()/1.42);
      $('.height').height($('.fiftyplus').width()/4.27);
      $('.double-big-height').height($('.fiftyminus').width()/0.473);
       $(window).resize(function(){
         $('.big-height').height($('.fiftyminus').width()/0.71);
         $('.height').height($('.fifty').width()/2.85);
         $('.big-height').height($('.fiftyplus').width()/2.13);
         $('.double-big-height').height($('.fiftyplus').width()/1.42);
         $('.double-big-height').height($('.fiftyplus').width()/1.42);
         $('.height').height($('.fiftyplus').width()/4.27);
         $('.double-big-height').height($('.fiftyminus').width()/0.473);
        });

      })
 }

  Drupal.behaviors.realtyStickyMenuScroll = {
    attach: $(function() {
      //  sticky menu
      $(window).load(function(){
        $("#header").sticky({ topSpacing: 0, className: 'sticky', wrapperClassName: 'my-wrapper' });
      });

      // jQuery for page scrolling feature - requires jQuery Easing plugin
      $('.page-scroll a').bind('click', function(event) {
        var $anchor = $(this);
        $('html, body').stop().animate({
          scrollTop: $($anchor.attr('href')).offset().top
        }, 1500, 'easeInOutExpo');
        event.preventDefault();
      });

    })
  }

  Drupal.behaviors.realtySearchTabel = {
    attach: $(function() {
      $(function() {
        $('#example').dataTable( {
          "paging":   false,
          "info":     false,
          "columnDefs": [ {
            "targets": [ 0, 1, 2, 3, 4, 11],
            "orderable": false
          } ]
      } );
      } );

      $(function () {
        $("[rel='tooltip']").tooltip();
      });
    })
  }

}(jQuery));
