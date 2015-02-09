(function ($) {

  Drupal.behaviors.realtyInit = {
    attach: $(function() {

      if(Drupal.settings.id) {
        $("body").attr("id","index");
      }

    })
  }


 Drupal.behaviors.realtyMultyselect = {
   attach: $(function() {

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
     var multiselect_modal = function(class_check_box, id_select, class_input) {
       var array_input = {};
       var string_input = '';
       $('.'+class_check_box).click(function () {
         var param =  $(this).val().split(';');
         if ($(this).prop("checked") == true ) {
           $('#'+id_select+' option[value='+param[0]+']').attr('selected', 'selected');
           array_input[param[1]] = param[1];

           string_input = '';
           $.each(array_input, function(key, val) {
             string_input == '' ?  string_input = val : string_input += ', '+val;
           });
           $('.'+class_input).val(string_input);
         }

         else{
           $('#'+id_select+' option[value='+param[0]+']').attr('selected', false);
           delete array_input[param[1]];
           string_input = '';
           $.each(array_input, function(key, val) {
             string_input == '' ?  string_input = val : string_input += ', '+val;
           });
           $('.'+class_input).val(string_input);
         }
       });
     }

     multiselect_modal('CheckboxArea', 'area', 'search-input-area');
     multiselect_modal('CheckboxRoom', 'room', 'search-input-room');
     multiselect_modal('CheckboxDeveloper', 'developer', 'search-input-developer');
     multiselect_modal('CheckboxMetro', 'metro', 'search-input-metro');
     multiselect_modal('CheckboxComplex', 'complex', 'search-input-complex');

     function complex_select(devid) {
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

     $('.decor_checkbox').each(function(){
       var checkbox = $('#parking');
       if(checkbox.prop("checked")) $(this).addClass("check_active");
     });

     $('.decor_checkbox').click(function() {
       var checkbox = $('#parking');
       if(checkbox.prop("checked")){
         $(this).removeClass("check_active");
         checkbox.prop("checked", false);
         checkbox.val(0);
       }else {
         $(this).addClass("check_active");
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
      });


      $('.CheckboxMapArea').click(function () {
        var select = $('select[id="edit-field-area-tid"]');
        $(this).prop("checked") == true ? $('#edit-field-area-tid option[value='+$(this).val()+']').attr('selected', 'selected') :
          $('#edit-field-area-tid option[value='+$(this).val()+']').attr('selected', false);
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
       $(window).resize(function() {
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

  Drupal.behaviors.realtyPlacemarkAddComplex = {
    attach: $(function(){
      $('#edit-field-home-complex-und').change(function(){
        console.log($(this).val());
      })
    })
    }

}(jQuery));
