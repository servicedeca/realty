(function ($) {

  Drupal.behaviors.realtyInit = {
    attach: $(function() {
     // jQuery.extend(Drupal.settings, {"devel":{"request_id":149027}});
      //window.alert = function(arg) { if (window.console && console.log) { console.log(arg);}};
      if(Drupal.settings.id) {
        $("body").attr("id","index");
      }
    })
  }

  Drupal.behaviors.realtyFotorama = {
    attach: $(function() {

      function ArrowMeter() {
        var height = $('.big-height').height();
        var result = height / 2.7;
        $('.fotorama__arr--prev').css('top', result);
        $('.fotorama__arr--next').css('top', result);
        $('.prev').css('top', result);
        $('.next').css('top', result);
      };

      var $fotoramaDiv = $('#3d').fotorama();
      var fotorama = $fotoramaDiv.data('fotorama');

      $(document).on('click', '.next', function() {
        fotorama.show('>');
        ArrowMeter();
      });
      $(document).on('click', '.prev', function() {
        fotorama.show('<');
        ArrowMeter();
      });

      ArrowMeter();
      $(window).resize(function(){
        ArrowMeter();
      });

    })
  }

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

      $(function() {
        $('#map-filter').change(function() {
          console.log($(this).val());
        }).multipleSelect({
          width: '100%'
        });
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
            $('.modal-map-complex .list-modal-city').html('');
            $('.modal-map-complex .list-modal-city').html(object.modal);
            $('#edit-field-home-complex-target-id').html('');
            if (object != null) {
              console.log(object.modal);
              $('.modal-map-complex .list-modal-city').html(object.modal);
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
      $("#download-id-apartment").click(function () {
        var nid = $(this).data('nid-apartment');
        console.log(nid);
        $.ajax({
          url: '/get_id_apartment',
          type: 'GET',

          data: {
            nid: nid
          },
          success: function(response) {

            console.log(response);
            if (response === 'user') {
              $('.close-modal').trigger('click');
              $('.head-reg').trigger('click');
            }
            else {
                var link = document.createElement('a');
                link.href = response;
                if (link.download !== undefined){
                  console.log(fileName);
                  var fileName = response.substring(response.lastIndexOf('/') + 1, response.length);
                  link.download = fileName;
                }
                if (document.createEvent) {
                  var e = document.createEvent('MouseEvents');
                  e.initEvent('click' ,true ,true);
                  link.dispatchEvent(e);
                  return true;
                }
              var query = '?download';
              window.open(response + query, '_self');
            }
          },
          error: function(response) {
            alert('false');
          }
        });
      });
    })
  }

  Drupal.behaviors.realtyBookingApartment = {
    attach: $(function () {
      $("#modal-free-booking-apartment").click(function () {
        if ($('.modal_free').length == 0) {
          $('li .head-reg').trigger('click');
        }
      });
    })
  }

  Drupal.behaviors.realtyApartmentSignal = {
    attach: $(function () {
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
      $(document).on('click', '.fotorama__arr--next', function(){
        dynamicChange();
      });
      $(document).on('click', '.next', function(){
        dynamicChange();
      });
      $(document).on('click', '.prev', function(){
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
        if ($('#home-'+id_section[1]+'-'+id_section[2]+'-' + id_section[3]).length > 0) {
          $('#home-'+id_section[1]+'-'+id_section[2]+'-'+id_section[3]).fadeIn(500);
        }
        else {
          for (var c = 1; c < 100; c++) {
            console.log($('#home-'+id_section[1]+'-'+id_section[2]+'-' + c).length);
            if ($('#home-'+id_section[1]+'-'+id_section[2]+'-' + c).length > 0) {
              $('#home-'+id_section[1]+'-'+id_section[2]+'-'+c).fadeIn(500);
              break;
            }
          }
        }
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


  Drupal.behaviors.realtyStockFilter = {
    attach: $(function(){
      var developer = $('.Checkbox-developer-stock'),
        selectDeveloper = $('#edit-field-developer-tid'),
        select = $('#select-developer');

      developer.click(function(){
        console.log($(this).val());
        if ($(this).prop("checked") == true ) {
          $('#edit-field-developer-tid option[value='+$(this).val()+']').attr('selected', 'selected');
        }
        else {
          $('#edit-field-developer-tid option[value='+$(this).val()+']').attr('selected', false);
        }
      });

      $('#select-developer-stock').click(function(){
        setTimeout(function(){
          $('#edit-submit-stock').trigger('click');
        },100)
      });
    })
  }

  Drupal.behaviors.realtyApartmentFilter = {
    attach: $(function(){
      var apartmentFilter = function () {
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
          }else {
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

        //  room type multiple select
        $(function() {
          $('.complex-filters #edit-field-number-rooms-value').change(function() {
            console.log($(this).val());
          }).multipleSelect({
            placeholder: 'Комнаты',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
          });
        });

        //  section type multiple select
        window.sections = {};
        $('#filter-form-section option').each(function() {
          window.sections[$(this).val()] = $(this).text();
        });

        var address = $("#filter-form-address").val(),
            sections = $('#edit-field-section-value').val();


        for (var en in window.selectedOP) {
          $('#filter-form-section option[value="'+window.selectedOP[en]+'"]').attr('selected', 'selected');
        }

        $('#filter-form-section').change(function() {
          var section,
            sections = $(this).val();
          for (var c in window.sections) {
            section = c.split(':');
            $('#edit-field-apartament-home-tid option[value='+section[1]+']').attr('selected', false);
          }
          var regExp = '(';
          for (var i in sections) {
            section = sections[i].split(':');
            regExp += section[0] + '$|';
            $('#edit-field-apartament-home-tid option[value='+section[1]+']').attr('selected', 'selected');
          }
          regExp = regExp.substr(0, regExp.length-2);
          regExp.length > 0 ?  regExp += '$)': regExp = null;
          if (regExp != 'null') {
            $('#edit-field-section-value').val(regExp);
          }

        })
          .multipleSelect({
            placeholder: 'Секция',
            selectAllText: 'Отметить все',
            allSelected: 'Все'
          });

        $(document).ready(function(){
          if ($('#edit-field-status-value').val() === '1') {
            $('#not-display-reserved').attr("checked","checked");
          }
          $('.complex-apartment-filter .dec_checkbox').each(function() {
            var checkbox = $(this).find('input[type=checkbox]');
            if(checkbox.prop("checked")) $(this).addClass("check_active");
          });
          $('.complex-apartment-filter .dec_checkbox').click(function(){
            var checkbox = $(this).find('input[type=checkbox]');
            if(checkbox.prop("checked")){
              $(this).removeClass("check_active");
              checkbox.prop("checked", false);
              $('#edit-field-status-value [value=All]').attr('selected', 'selected');
              $('#edit-submit-apartments').trigger('click');
            }else{
              $(this).addClass("check_active");
              checkbox.prop("checked", true);
              $('#edit-field-status-value [value=1]').attr('selected', 'selected');
              $('#edit-submit-apartments').trigger('click');
            }
          });
        });

        $(document).on('click', '.complex-filter-clear-button',function () {
          window.selectedOP = $('#filter-form-section').val();
          $('#edit-submit-apartments').trigger('click');
        });
      }

      apartmentFilter();
      $(document).ajaxSuccess(function() {
        apartmentFilter();
      })
    })


  }

  Drupal.behaviors.realtyGallery = {
    attach: $(function(){
      var i = 0;
      while (1) {
        if ($('.album-'+i).length > 0) {
          $('.album-'+i).magnificPopup({
            delegate: 'a',
            type: 'image',
            mainClass: 'mfp-img-mobile',
            gallery: {
              enabled: true,
              navigateByImgClick: true,
              preload: [0,1] // Will preload 0 - before current, and 1 after the current image
            }
          });
          i++;
          continue;
        } else {
          break;
        }
      }
      $('.visual-album').magnificPopup({
        delegate: 'a',
        type: 'image',
        mainClass: 'mfp-img-mobile',
        gallery: {
          enabled: true,
          navigateByImgClick: true,
          preload: [0,1] // Will preload 0 - before current, and 1 after the current image
        }
      });
    })
  }

  Drupal.behaviors.realtyComplexStock = {
    attach: $(function(){
      $(document).ready(function() {

        $("#owl-demo").owlCarousel({

          navigation : true, // Show next and prev buttons
          slideSpeed : 300,
          paginationSpeed : 400,
          singleItem:true

          // "singleItem:true" is a shortcut for:
          // items : 1,
          // itemsDesktop : false,
          // itemsDesktopSmall : false,
          // itemsTablet: false,
          // itemsMobile : false

        });
        $('.owl-next').html('');
        $('.owl-prev').html('');
      });
    })
  }

  Drupal.behaviors.realtyAdditionalFieldsPayment = {
    attach: $(function(){
      $('#edit-payment-2').click(function(){
        if ($(this).prop('checked')) {
          $('.payment-additional-fields').show();
        }
      });
      $('#edit-payment-0').click(function(){
        $('.payment-additional-fields').hide();
      });
      $('#edit-payment-1').click(function(){
        $('.payment-additional-fields').hide();
      });
    })
  }

  Drupal.behaviors.events = {
    attach: function(context, settings) {
      $('body').bind('ajaxSuccess', function(data, status, xhr) {
        alert('ok');
      });
    }
  };

  Drupal.behaviors.realtyRegModal = {
    attach: $(function(){
      $(document).ready(function(){
        $(".reg-item").click(function(){
          if($(this).attr('class')  ==  'reg-item' ) {
            $('.reg-item').removeClass('reg-active');
            $(this).addClass('reg-active');
          }
        })
      });
    })
  }
}(jQuery));
