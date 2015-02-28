(function ($) {

  Drupal.behaviors.realtyInit = {
    attach: $(function() {

      if(Drupal.settings.id) {
        $("body").attr("id","index");
      }
    })
  }

  Drupal.behaviors.realtyFotorama = {
    attach: $(function() {

      var $fotoramaDiv = $('#3d').fotorama();
      var fotorama = $fotoramaDiv.data('fotorama');

      $('.next').click(function() {
        fotorama.show('>');
      });
      $('.prev').click(function() {
        fotorama.show('<');
      });

      function ArrowMeter(){
        var height = $('.big-height').height();
        var result = height / 2.7;
        $('.fotorama__arr--prev').css('top', result);
        $('.fotorama__arr--next').css('top', result);
        $('.prev').css('top', result);
        $('.next').css('top', result);
      };
      ArrowMeter();
      $(window).resize(function(){
      ArrowMeter();
      });

    })
  }


 Drupal.behaviors.realtyFormSearch = {
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
     if(Drupal.settings.get) {
       var sq =  Drupal.settings.get.sq.split(';');
       var price = Drupal.settings.get.price.split(';');
       var coast = Drupal.settings.get.coast.split(';');
     }

     $(".sq").ionRangeSlider({
       hide_min_max: true,
       keyboard: true,
       min: 0,
       max: 200,
       postfix: "  м<sup>2</sup>",
       from: sq ? sq[0] : 30 ,
       to:  sq ? sq[1] : 150 ,
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
       from: price ? price[0] : 55,
       to: price ? price[1  ] :85,
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
       from: coast ? coast[0] : 1.6,
       to: coast ? coast[1] : 4,
       type: 'double',
       step: 0.2,
       grid: true,
       hasGrid: true
     });
     devid={};
     var multiselect_modal = function(class_check_box, id_select, class_input) {
       var array_input = {};
       var string_input = '';
       $(document).on('click', '.'+class_check_box, function(){
         var param =  $(this).val().split(';');
         if ($(this).prop("checked") == true ) {
           $('#'+id_select+' option[value='+param[0]+']').attr('selected', 'selected');
           array_input[param[1]] = param[1];

           if (class_check_box == 'CheckboxDeveloper') {
             devid[param[0]] = param[0];
             $('.search-input-complex').val('');
             complex_select(devid);
           }

           string_input = '';
           $.each(array_input, function(key, val) {
             string_input == '' ?  string_input = val : string_input += ', '+val;
           });
           $('.'+class_input).val(string_input);
         }

         else {
           $('#'+id_select+' option[value='+param[0]+']').attr('selected', false);
           delete array_input[param[1]];
           string_input = '';
           $.each(array_input, function(key, val) {
             string_input == '' ?  string_input = val : string_input += ', '+val;
           });
           $('.'+class_input).val(string_input);

           if (class_check_box == 'CheckboxDeveloper') {
             delete devid[param[0]];
             $('.search-input-complex').val('');
             complex_select(devid);
           }
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


  Drupal.behaviors.realtyFormSearchGetParam = {
    attach: $(function () {
      if (Drupal.settings.get) {
        if (Drupal.settings.get.area) {
         $.each(Drupal.settings.get.area, function(key, val){
          $('.area-'+val).trigger('click');
         });
        }
        if (Drupal.settings.get.developer) {
          $.each(Drupal.settings.get.developer, function(key, val){
            $('.developer-'+val).trigger('click');
          });
        }
        if (Drupal.settings.get.category) {
          $.each(Drupal.settings.get.category, function(key, val){
            $('.room-'+val).trigger('click');
          });
        }
        if (Drupal.settings.get.complex) {
          $.each(Drupal.settings.get.complex, function(key, val){
              $('.complex-'+val).trigger('click');
          });
        }
        if (Drupal.settings.get.metro) {
          $.each(Drupal.settings.get.metro, function(key, val){
            $('.metro-'+val).trigger('click');
          });
        }
      }
    })
  };


  Drupal.behaviors.realtySearchMap = {
    attach: $(function () {
      $("#map-filter").change(function () {
        var select = $('select[id="edit-field-category-value"]');
        select.val($(this).val());
      });


      function complex_select_map(devid) {
        var city = Drupal.settings.city;
        $.ajax({
          url: '/get_developer_complex',
          type: 'POST',
          data: {
            developer: devid,
            city: city,
            map: 1
          },
          success: function(response) {
            var object = jQuery.parseJSON(response);
            console.log(response);
            $('.complexes-lis-map').html('');
            $('#edit-field-home-complex-target-id').html('');
            if (object != null) {
              $('.complexes-lis-map').html(object.modal);
              $('#edit-field-home-complex-target-id').html(object.select);
            }
          },
          error: function(response) {
            alert('false');
          }
        });
      }

      map_devid = {};
      $('.CheckboxMapArea').click(function () {
        var select = $('select[id="edit-field-area-tid"]');
        $(this).prop("checked") == true ? $('#edit-field-area-tid option[value='+$(this).val()+']').attr('selected', 'selected') :
          $('#edit-field-area-tid option[value='+$(this).val()+']').attr('selected', false);
      });
      $(document).on('click', '.CheckboxMapComplex',function () {
        var select = $('select[id="edit-field-home-complex-target-id"]');
        $(this).prop("checked") == true ? $('#edit-field-home-complex-target-id option[value='+$(this).val()+']').attr('selected', 'selected') :
          $('#edit-field-home-complex-target-id option[value='+$(this).val()+']').attr('selected', false);
      });

      $('.CheckboxMapDeveloper').click(function () {
        var param =  $(this).val()
        if($(this).prop("checked") == true ) {
          $('#edit-field-complex-developer-tid option[value='+$(this).val()+']').attr('selected', 'selected');
          map_devid[param] = param;
          complex_select_map(map_devid);
        }
        else {
          $('#edit-field-complex-developer-tid option[value='+$(this).val()+']').attr('selected', false);
          delete map_devid[param];
          complex_select_map(map_devid);
        }
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

      $("#apartment-signal").click(function () {

        var nid = $(this).data('node-id');
        $.ajax({
          url: '/apartment_signal',
          type: 'POST',
          data: {
            nid: nid
          },
          success: function(response) {
            if(response == 'user') {
              window.location.replace('user');
            }
            else if(response == true) {
              $('#signal').html('');
              $('#signal').html('<a href="#apartment-signal" rel="tooltip" data-placement="right" title="" data-original-title="уведомление отправится о снятии брони">' +
                '<img class="dingdong" src='+Drupal.settings.REALTY_FRONT_THEME_PATH +'/images/dingdong.svg>' +
                '</a>');
            }
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
            "targets": [ 0,1,2,3,4],
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
        $('#edit-field-home-complex-und').change(function() {
          console.log($(this).val());
        })
      })
    }

  Drupal.behaviors.realty = {
    attach: $(function(){
      $('#edit-field-home-complex-und').change(function() {
        console.log($(this).val());
      })
    })
  }

}(jQuery));
