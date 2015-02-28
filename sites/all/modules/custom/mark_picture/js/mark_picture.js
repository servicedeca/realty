(function ($) {
  Drupal.behaviors.mark_pictureHomeInit = {
    attach: $(function() {
      var complex = $('#edit-field-home-complex-und');
      $('#add-home-plan').click(function() {
        console.log($('#edit-field-home-complex-und').val());
        if (complex.val() == '_none') {
          $('.div-plan-complex').html('');
          $('.div-plan-complex').html('<p class="error-add-complex">Выбирете жилой комплекс</p>');
        }
        else {
          $.ajax({
            url: '/add_plan_complex',
            type: 'POST',
            data: {
              nid: complex.val()
            },
            success: function(response) {
              var object = jQuery.parseJSON(response);
              if(object.img) {
                $('.div-plan-complex').html('');
                $('.div-plan-complex').html(object.img);
              }
              console.log(object);
            },
            error: function(response) {
              alert('false');
            }
          });
        }
      });

      $('#edit-field-home-complex-und').change(function() {
        console.log($(this).val());
      });

      var tool_add_mark = function (tool, div, mark) {

        $(tool).click(function() {
          if($(this).hasClass('tool-add-active')) {
            $(this).removeClass('tool-add-active');
            $('.'+div).removeClass(div + '-active');
          }
          else {
            $(this).addClass('tool-add-active');
            $('.'+div).addClass(div + '-active');
            coordinates_cursor(tool, div, mark);
          }
        })
      }

      var coordinates_cursor = function (tool, element, mark) {
         $('.'+element).click(function(e) {
           console.log(element);
           if ($(tool).hasClass('tool-add-active')) {

             var offset = $(this).offset(), top, left;
             top = Math.ceil(100*(e.pageY -  offset.top)/$(this).height());
             left = Math.ceil(100*(e.pageX - offset.left)/$(this).width());
             window.cordinat = {
               top : top,
               left: left
             }
             console.log(window.cordinat);

             $('.'+element).append('<div class="dialog" style="position: absolute; left:'+window.cordinat.left+'%; top:'+window.cordinat.top+'% ; z-index: 100;"> ' +
               '<a class="save-'+mark+'">Сохранить</a> ' +
               '<a class="del-'+mark+'">Удалить</a> ' +
               '</div>');

             $(tool).trigger('click');
             $(tool).hide();
           }
           else {
             return 0;
           }
         })
      }


      var save_mark_cordinat = function(clss_div, id_input_cordinat, tool, mark) {
        $(document).on('click', '.save-'+mark+'', function() {
          $('.dialog').remove();
          console.log(window.cordinat);
          $('.' + clss_div).append('<div class="mark '+mark+'" style="position: absolute; left:'+window.cordinat.left+'%; top:'+window.cordinat.top+'% ; z-index: 100;"> ' +
            '</div>');

          $('#' + id_input_cordinat).val(JSON.stringify(window.cordinat));
        });

        $(document).on('click', '.del-'+mark+'', function() {
          $('.dialog').remove();
          $('.'+tool).show();
        });

        $(document).on('click', '.'+mark+'', function() {
          $('.mark').remove();
          $('.' + clss_div).append('<div class="dialog" style="position: absolute; left:'+window.cordinat.left+'%; top:'+window.cordinat.top+'% ; z-index: 100;"> ' +
            '<a class="save-'+mark+'">Сохранить</a> ' +
            '<a class="del-'+mark+'">Удалить</a> ' +
            '</div>');
          $('.'+tool).show();
        });
      }


      tool_add_mark('.tool-add-complex', 'div-plan-complex', 'complex');
      save_mark_cordinat('div-plan-complex', 'edit-field-lage-plan-complex-und-0-value', 'tool-add-complex', 'complex');



      var home_plan;
      $('.form-item-field-home-plan-und-0 .file a').length > 0 ?
        home_plan = $('.form-item-field-home-plan-und-0 .file a') :
        home_plan = false;
      console.log(home_plan);

      $('#add-section-plan').click(function() {
        if($('.form-item-field-home-plan-und-0 .file a').length > 0) {
          home_plan = $('.form-item-field-home-plan-und-0 .file a');
          $('.div-plan-home').html('');
          $('.div-plan-home').append('<img src="'+home_plan.attr("href")+'">');
        }
        else {
          $('.div-plan-home').html('');
          $('.div-plan-home').append('Загрузите план дома!!!');
        }

      });

      var coordinates_cursor_section = function (tool, element, mark) {
        $('.'+element).click(function(e) {
          if ($(tool).hasClass('tool-add-active')) {

            var offset = $(this).offset(), top, left;
            top = Math.ceil(100*(e.pageY -  offset.top)/$(this).height());
            left = Math.ceil(100*(e.pageX - offset.left)/$(this).width());

            window.cordinat = {
              top : top,
              left: left
            }

            console.log(window.cordinat);

            $('.'+element).append('<div class="dialog" style="position: absolute; left:'+window.cordinat.left+'%; top:'+window.cordinat.top+'% ; z-index: 100;"> ' +
              'Номер секции'+
              '<input type="text" class="form-text" id="dialog-number-section">' +
              '<a class="save-'+mark+'">Сохранить</a> ' +
              '<a class="delete-dialog">Удалить</a> ' +
              '<p class="error-dialog"></p>'+
              '</div>');

            $(tool).trigger('click');
          }
          else {
            return 0;
          }
        })
      }

      $('.tool-add-section').click(function() {
        if($(this).hasClass('tool-add-active')) {
          $(this).removeClass('tool-add-active');
          $('.div-plan-home').removeClass('div-plan-home-active');
        }
        else {
          $(this).addClass('tool-add-active');
          $('.div-plan-home').addClass('div-plan-home-active');
          coordinates_cursor_section('.tool-add-section', 'div-plan-home', 'section');
        }
      });

      var delete_mark_sektion = function(id) {
        $('#'+id).remove();
        $('.dialog').remove();
      }

      var save_mark_cordinat_section = function(mark, class_div) {

        //Saving mark
        $(document).on('click', '.save-'+mark+'', function() {
          var id_sec = $('#dialog-number-section').val();
          var i = 0;
          while(true) {
            if($('#edit-field-home-section-und-'+i+'-field-number-section-und-0-value').val() == '') {
              break;
            }
            else {
              i++;
            }
          }
          console.log($('#section-'+id_sec+'-'+i).length);
          if($('.section-'+id_sec).length > 0) {
            $('.dialog .error-dialog').html('Секция уже существует');
          }
          else if(id_sec == '') {
            $('.dialog .error-dialog').html('Введите номер');
          }
          else {
            $('#edit-field-home-section-und-'+i+'-field-number-section-und-0-value').val(id_sec);
            $('#edit-field-home-section-und-'+i+'-field-lage-plan-home-und-0-value').val(JSON.stringify(window.cordinat));
            $('.dialog').remove();
            $('.' + class_div).append('<div id="section-'+id_sec+'-'+i+'" class="mark '+mark+' section-'+id_sec+'" style="position: absolute; left:'+window.cordinat.left+'%; top:'+window.cordinat.top+'% ; z-index: 100;"> ' +
              id_sec+
              '</div>');
          }
        });

        //Removing mark
        $(document).on('click', '.del-'+mark+'', function() {
          var id_section_del = $(this).attr('id').split('-');
          $('#edit-field-home-section-und-'+id_section_del[2]+'-field-number-section-und-0-value').val('');
          $('#edit-field-home-section-und-'+id_section_del[2]+'-field-lage-plan-home-und-0-value').val('');
          $('#section-'+id_section_del[1]+'-'+id_section_del[2]).remove();
          $('.dialog').remove();
        });

        //Removing dialog
        $(document).on('click', '.delete-dialog', function() {
          $('.dialog').remove();
        });

        $(document).on('click','.save-mark', function(){
          $('.dialog').remove();
        });

        $(document).on('click', '.'+mark+'', function(e) {
          var id_section = $(this).attr('id');
          var cord = $(this).position();
          var top = Math.ceil(100*(cord.top)/$('.div-plan-home').height());
          var left = Math.ceil(100*(cord.left)/$('.div-plan-home').width());
          $('.' + class_div).append('<div class="dialog" style="position: absolute; left:'+left+'%; top:'+top+'% ; z-index: 100;"> ' +
            '<a class="save-mark">Сохранить</a> ' +
            '<a class=" del-'+mark+' " id=del'+id_section+'>Удалить</a> ' +
            '</div>');
        });
      }

      save_mark_cordinat_section('section', 'div-plan-home');

    })
  }




}(jQuery));
