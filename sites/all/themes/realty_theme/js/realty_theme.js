(function ($) {

 Drupal.behaviors.realtyMultyselect = {
   attach: $(function() {
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
   })
  };


  Drupal.behaviors.realtySelectcomplex = {
    attach: $(function () {
      $("#developer").change(function () {
        complex_select($(this).val());
      });
      function complex_select(devid){
        var city = $('input[name="city"]');
        var complexSelect = $('select[name="complex"]');
        var developerSelect = $('select[name="developer"]');
        //console.log(developerSelect);
        $.ajax({
          url: '/get_developer_complex',
          type: 'POST',
          data: {
            developer: devid,
            city: city.val()
          },
          success: function(response) {
            var object = jQuery.parseJSON(response);
            complexSelect.html('');
            complexSelect.html(object.option);

            complexSelect.append(response);
            $('.form-item-complex .ms-parent ul').html('');
            $('.form-item-complex .ms-parent ul').html(object.li);
          },
          error: function(response) {
            alert('false');
          }
        });
      }
    })
  };

  Drupal.behaviors.realtySearchMap = {
    attach: $(function () {
      $("#category-map").change(function () {
        var select = $('select[id="edit-field-category-value"]');
        select.val($(this).val());
        $('#edit-submit-map').trigger('click');
      });
      $("#area-map").change(function () {
        var select = $('select[id="edit-field-area-tid"]');
        select.val($(this).val());
        $('#edit-submit-map').trigger('click');
      });
      $("#masonry-map").change(function () {
        var select = $('select[id="edit-field-masonry-value"]');
        select.val($(this).val());
        $('#edit-submit-map').trigger('click');
      });
      $("#parking-map").click(function () {
        var select = $('select[id="edit-field-parking-value"]');
        $(this).prop("checked") == true ? select.val(1) :  select.val(2);
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

  Drupal.behaviors.realtyStickyMenu = {
    attach: $(function() {
              //  sticky menu
              $(window).load(function(){
                $("#header").sticky({ topSpacing: 0, className: 'sticky', wrapperClassName: 'my-wrapper' });
              });
            })
  }
}(jQuery));
