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
        //resizeBigHeight();
      });
      $('.prev').click(function() {
        fotorama.show('<');
        //resizeBigHeight();
      });



    })
  }


 Drupal.behaviors.realtyFormSearch = {
   attach: $(function() {

   $(document).on('click', '.complex-filter-clear-button',function () {
     $('#edit-submit-apartments').trigger('click');
   });


   var multiple_select_form = function() {
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

     $('.span-checkbox-area').click(function(){
       var classCheckbox,
           id = $(this).attr('id');
       var idLeng = id.length;
       var id = id.slice(6, idLeng);
           console.log(id);
       //$($(this).attr('id')+'  CheckboxArea').trigger('click');
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

     //  adress type multiple select
     $(function() {
       window.all_select = $('#filter-form-section').html();

       var change_select_list = function (homes) {
         var group = {};
         if (homes != null) {
           for (var i in homes) {
             group[$("#filter-form-address [value='"+homes[i]+"']").val()] = $("#filter-form-address [value='"+homes[i]+"']").text();
           }
         }
         if(!$.isEmptyObject(group)) {
           var select_html = null;
           for(var j in group) {
             if (select_html != null) {
               select_html += '<optgroup label="'+group[j]+'">';
             }
             else {
               select_html = '<optgroup label="'+group[j]+'">';
             }

             for(var k in window.sections) {
               var key = k.split(':');
               if (key[1] === j) {
                 select_html += '<option value="'+key[0]+':'+key[1]+'">'+key[0]+'</option>';
               }
             }
             select_html += '</optgroup>';
           }
           return select_html;
         }

         else {
           return window.all_select;
         }
       }

       $("#filter-form-address").val($('#edit-field-apartament-home-tid').val());
       $('#filter-form-section').html('')
         .html(change_select_list($('#edit-field-apartament-home-tid').val()));


       $('#filter-form-address').change(function() {
         var homes;
         homes = $(this).val();
         $('#filter-form-section').html('')
           .html(change_select_list(homes))
           .multipleSelect({
             placeholder: 'Секция',
             selectAllText: 'Отметить все',
             allSelected: 'Все'
           });
         $('#edit-field-apartament-home-tid').val($(this).val());
       })
       .multipleSelect({
       placeholder: 'Адрес дома',
       selectAllText: 'Отметить все',
       allSelected: 'Все'
       });
     });

     //  section type multiple select
     $(function() {
       window.sections = {};

       $('#filter-form-section option').each(function() {
         window.sections[$(this).val()] = $(this).text();
       });

       var address = $("#filter-form-address").val();
       var sections = $('#edit-field-section-value').val();
       if ($("#filter-form-address").val() != null) {
         for (var e in address) {
            for (var en in sections) {
              var option = sections[en]+':'+address[e];
              console.log(option);
              $('#filter-form-section option[value="'+option+'"]').attr('selected', 'selected');
            }
          }
         }


       $('#filter-form-section').change(function() {
         var section;
         var sections = $(this).val();

         for (var c in window.sections) {
           section = c.split(':');
           $('#edit-field-section-value option[value='+section[0]+']').attr('selected', false);
           $('#edit-field-apartament-home-tid option[value='+section[1]+']').attr('selected', false);
         }
         for (var i in sections) {
           section = sections[i].split(':');
           $('#edit-field-section-value option[value='+section[0]+']').attr('selected', 'selected');
           $('#edit-field-apartament-home-tid option[value='+section[1]+']').attr('selected', 'selected');
         }
       })

       .multipleSelect({
         placeholder: 'Секция',
         selectAllText: 'Отметить все',
         allSelected: 'Все'
       });
     });


//  room type multiple select
     $(function() {
       $('#edit-field-number-rooms-value').change(function() {
         console.log($(this).val());
       }).multipleSelect({
         placeholder: 'Комнаты',
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

     $(document).ready(function(){
       if ($('#edit-field-status-value').val() === '1') {
         $('#not-display-reserved').attr("checked","checked");
       }

       $('.dec_checkbox').each(function(){
         var checkbox = $(this).find('input[type=checkbox]');
         if(checkbox.prop("checked")) $(this).addClass("check_active");
       });

       // при клике по диву, делаем проверку
       $('.dec_checkbox').click(function(){
         var checkbox = $(this).find('input[type=checkbox]');
         // если чекбокс был активен
         if(checkbox.prop("checked")){
           // снимаем класс с родительского дива
           $(this).removeClass("check_active");
           // и снимаем галочку с чекбокса
           checkbox.prop("checked", false);
           // если чекбокс не был активен
           $('#edit-field-status-value [value=All]').attr('selected', 'selected');
           $('#edit-submit-apartments').trigger('click');
         }else{
           // добавляем класс родительскому диву
           $(this).addClass("check_active");
           // ставим галочку в чекбоксе
           checkbox.prop("checked", true);
           $('#edit-field-status-value [value=1]').attr('selected', 'selected');
           $('#edit-submit-apartments').trigger('click');
         }
       });



     });

   };

    multiple_select_form();
    $(document).ajaxSuccess(function() {
      multiple_select_form();
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
            console.log(object);
            $('#complexes-lis-map').html(object.modal);
           // $('#complex-list-map').html('');
            $('#edit-field-home-complex-target-id').html('');
            if (object != null) {
              console.log(object.modal);
              $('#complexes-lis-map').html(object.modal);
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

      $(document).on('click', '.apartment-comparison',function () {
        var apartment = $(this);
          var nid = $(this).data('node-id');
          var apart = 0;
        if ($(this).data('apartment') > 0){
          apart = $(this).data('apartment');
        }
          $.ajax({
            url: '/apartment_comparison',
            type: 'POST',
            data: {
              nid: nid,
              apartment: apart
            },
            success: function(response) {
              console.log(response);
              if (response != 1) {
                apartment.html('');
                apartment.html(response);
              }
              else {
                return;
              }
            },
            error: function(response) {
              alert('false');
            }
          });
      });


      $(document).on('click', '.apartment-signal',function () {
        var apartment = $(this);
        var nid = $(this).data('node-id');
        var apart = 0;
        console.log(nid);
        if ($(this).data('apartment') > 0){
          apart = $(this).data('apartment');
        }
        $.ajax({
          url: '/apartment_signal',
          type: 'POST',
          data: {
            nid: nid,
            apartment: apart
          },
          success: function(response) {
            if(response == 'user') {
              window.location.replace('user');
            }
            if (response != 1) {
              apartment.html('');
              apartment.html(response);
            }
            else {
              return;
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
      var dynamicChange = function(){
        $('.big-height').height($('.fiftyminus').width()/0.71);
        $('.height').height($('.fifty').width()/2.85);
        $('.big-height').height($('.fiftyplus').width()/2.13);
        $('.double-big-height').height($('.fiftyplus').width()/1.42);
        $('.double-big-height').height($('.fiftyplus').width()/1.42);
        $('.height').height($('.fiftyplus').width()/4.27);
        $('.double-big-height').height($('.fiftyminus').width()/0.473);
      }
      $(window).ready(function(){
        dynamicChange();
      });

      $(window).resize(function() {
        dynamicChange();
      });

      $(document).on('click', '.fotorama__arr--next', function(){
        dynamicChange();
      });
      $(document).on('click', '.fotorama__arr--prev', function(){
        dynamicChange();
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


  Drupal.behaviors.realtySortApartment = {
    attach: $(function() {
      var order = 0;
      var temp_param = 0;
      var param;
      var this_class;

      $(document).ajaxSuccess(function() {
        console.log(this_class);
        $(this_class).removeClass('sorting');
        if (temp_param != param) {
          if (order === 'ASC' || order === 0) {
            $(this_class).removeClass('sorting');
            $(this_class).addClass('sorting-up');
          }
          else if (order === 'DESC') {
            $(this_class).removeClass('sorting');
            $(this_class).removeClass('sorting-down');
            $(this_class).addClass('sorting-up');
          }
        }
        else {
          $(this_class).removeClass('sorting');
          $(this_class).removeClass('sorting-up');
          $(this_class).addClass('sorting-down ');
        }
      });

      $(document).on('click', '.sort', function() {
        this_class = $(this);
        param = $(this).data('sort');
        if (temp_param != param) {
          if (order === 'ASC' || order === 0) {
            $('#edit-sort-by option[value='+param+']').attr('selected', 'selected');
            $('#edit-sort-order option[value=ASC]').attr('selected', 'selected');
            $('#edit-submit-apartments').trigger('click');
            temp_param = param;
            $(this).removeClass('sorting');
            $(this).addClass('sorting-up');
          }
          else if (order === 'DESC') {
            $('#edit-sort-by option[value='+param+']').attr('selected', 'selected');
            $('#edit-sort-order option[value=DESC]').attr('selected', 'selected');
            $('#edit-submit-apartments').trigger('click');
            order = 'ASC';
            temp_param = 0;
            $(this).removeClass('sorting');
            $(this).removeClass('sorting-down');
            $(this).addClass('sorting-up');
          }
        }
        else {
          $('#edit-sort-by option[value='+param+']').attr('selected', 'selected');
          $('#edit-sort-order option[value=DESC]').attr('selected', 'selected');
          $('#edit-submit-apartments').trigger('click');
          order = 'ASC';
          temp_param = 0;
          $(this).removeClass('sorting');
          $(this).removeClass('sorting-up');
          $(this).addClass('sorting-down ');
        }
      })
    })
  }

  Drupal.behaviors.realtyPlacemarkAddComplex = {
    attach: $(function(){
        $('#edit-field-home-complex-und').change(function() {
          console.log($(this).val());
        })
      })
    }

  Drupal.behaviors.realtyCommentAJAX = {
    attach: $(function(){
      $('#realty-comment-submit').click(function() {
        var comment = $('#realty-comment-form-input').val();
        var nid = $('#realty-comment-submit').data('node-id');
        if(comment != '') {
          $.ajax({
            url: '/realty_add_comment',
            type: 'POST',
            data: {
              comment: comment,
              nid: nid
            },
            success: function(response) {
              if (response) {
                $('.hint-comment-block')
                  .html('')
                  .html('<p class="textarea-send-text">'+Drupal.t('Your review has been sent!')+'</p>');
                $('#realty-comment-form-input').val('');
              }
              else {
                alert(Drupal.t('Error! Contact the administrator of the site.'));
              }
            },
            error: function(response) {
              alert('false');
            }
          });
        }
        else {
          $('.hint-comment-block')
            .html('')
            .html('<p class="textarea-error-text">'+Drupal.t('Write a comment!!')+'</p>');
            $('.form-control').addClass('textarea-error');
        }
        setTimeout(function(){
          $('.hint-comment-block').html('')
          $('.form-control').removeClass('textarea-error');
        },2000);

        console.log($('#realty-comment-form-input').val());
      });
    })
  }


  Drupal.behaviors.realtyPlanComplex = {
    attach: $(function(){
      $('.plan-complex-home').click(function(){
        var id_home = $(this).attr('id').split('-');
        $('#complex-plan').hide();
        $('.plan-home-section-floor').hide();
        $('#home-'+id_home[1]+'-plan').fadeIn(500);
        console.log(id_home);
      });

      $('.plan-complex-home-section').click(function(){
        var id_section = $(this).attr('id').split('-');
        $('#complex-plan').hide();
        $('.plan-home-section').hide();
        $('.plan-home-section-floor').hide();
        $('#home-'+id_section[1]+'-'+id_section[2]+'-'+id_section[3]).fadeIn(500);
      });

      $('.over-plan').click(function(){
        $('.plan-home-section').hide();
        $('.plan-home-section-floor').hide(500);
        $('#complex-plan').fadeIn();
      });
    })
  }

  Drupal.behaviors.realtyPageApatment = {
    attach: $(function() {
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
    })
  }


  Drupal.behaviors.realtyComplexesFilter = {
    attach: $(function(){
      var developer = $('.Checkbox-developer'),
          selectDeveloper = $('#edit-field-complex-developer-tid'),
          select = $('#select-developer');

      developer.click(function(){
        console.log($(this).val());
        if ($(this).prop("checked") == true ) {
          $('#edit-field-complex-developer-tid option[value='+$(this).val()+']').attr('selected', 'selected');
        }
        else {
          $('#edit-field-complex-developer-tid option[value='+$(this).val()+']').attr('selected', false);
        }
      });

       $('#select-developer').click(function(){
        setTimeout(function(){
          $('#edit-submit-complex').trigger('click');
        },100)
      });
    })
  }

}(jQuery));
