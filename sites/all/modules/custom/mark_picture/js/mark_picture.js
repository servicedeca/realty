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

  /**
   *
    * @type {{attach: attach}}
   *
   */

  Drupal.behaviors.mark_pictureAprtment = {
    attach: function(){
      var addApartmentsPlan = $('#add-apartments-plan');

      function scanFloors () {
        var tablePlanFloors = $('field-plan-floor-values'),
            i = 0,
            j = 0,
            k = 0,
            imageFloors,
            floors,
            floor,
            optionsFloors = {},
            htmlBlock = '<div></div>',
            sections,
            apartmentValue,
            apartmentObject,
            apartment,
            stringFloor;

        while (1) {
          if ($('#edit-field-plan-floor-und-'+i+'-field-image-plan-floor-und-0-ajax-wrapper .file a').length > 0) {
            imageFloors = $('#edit-field-plan-floor-und-'+i+'-field-image-plan-floor-und-0-ajax-wrapper .file a').attr('href');
            sections = $('#edit-field-plan-floor-und-'+i+'-field-plan-number-section-und-0-value');
            floors = $('#edit-field-plan-floor-und-'+i+'-field-plan-number-floor-und-0-value');
            apartmentValue = $('#edit-field-plan-floor-und-'+i+'-field-apartments-und-0-value');
            stringFloor = floors.val();
            if (sections.val() != '' && floors.val() != '') {
              optionsFloors[i] = [sections.val(), floors.val(), imageFloors, apartmentValue.val()];
            }
            else {
              i++;
              continue;
            }
          }
          else {
            break;
          }
          i++;
        }
        for (floor in optionsFloors) {
          if(optionsFloors[floor][3] != '') {
            console.log(optionsFloors[floor][3]);
            apartmentObject = jQuery.parseJSON(optionsFloors[floor][3]);
            console.log(apartmentObject[0]);
          }
          htmlBlock += '<div class="floors-html-block">'+
            '<div class="title-floor-section">Секция: '+optionsFloors[floor][0]+
            '<br>Этажи: '+optionsFloors[floor][1]+'</div>'+
            '<div>' +
            '<img src="http://realty/sites/all/modules/custom/mark_picture/images/centre.png" width="25px" ' +
            'id="tool-'+floor+'" '+
            'class="tool-add tool-add-apartment">'+
            '</div>'+
            '<div class="floor-plan-image" id="plan-'+floor+'">'+
            '<img src="'+optionsFloors[floor][2]+'">';
             if(optionsFloors[floor][3] != '') {
               for (apartment in apartmentObject[0]) {
                 htmlBlock += '<div class="mark mark-apartment" id="mark-'+j+'-'+k+'" style="position: absolute; left:'+apartmentObject[0][apartment]['left']+'%; top:'+apartmentObject[0][apartment]['top']+'% ; z-index: 100;">'+k+'</div>';
                 k++;
               }
             }
          htmlBlock +='</div>'+
          '</div>';
          j++;
        }

        return htmlBlock;
      };


      addApartmentsPlan.click(function() {
        $('#add-apartments-plan-form').html('')
          .html(scanFloors());
      });

      // tool selection.
      $(document).on('click','.tool-add-apartment', function() {
        var toolId;
        if($(this).hasClass('tool-add-active')) {
          $(this).removeClass('tool-add-active');
          toolId = $(this).attr('id').split('-');
          $('#plan-'+toolId[1]).removeClass('floor-plan-image-active');
        }
        else {
          $('.tool-add').removeClass('tool-add-active');
          $('.floor-plan-image').removeClass('floor-plan-image-active');

          $(this).addClass('tool-add-active');

          toolId = $(this).attr('id').split('-');
          $('#plan-'+toolId[1]).addClass('floor-plan-image-active');
          console.log(toolId);
        }
      });

      //box filled apartments
      function windowDialog(top, left, id, markId) {
        var planId = id,
            apartmentsValue = $('#edit-field-plan-floor-und-'+id+'-field-apartments-und-0-value').val(),
            apartmentsObject,
            i = 0,
            htmlDialog = '<div class="floor-window-dialog" style="position: absolute; left:'+left+'%; top:'+top+'% ; z-index: 100;">'+
              '<p><b>номер кв</b></p>&nbsp;&nbsp;<p><b>этаж</b></p>'+
              '<div class="form-block-input">';

        for(i ; i < 10 ; i++) {
          htmlDialog += '<input type="text" class="input-form-dialog-apartment" id="apartment-number-'+i+'">&nbsp;&nbsp;' +
            '<input type="text" class="input-form-dialog-apartment" id="floor-number-'+i+'"><br>'
        }



        htmlDialog += '</div>' +
          '<a href="#href" class="save-apartment-plan" id="save-apartment-plan-'+id+'-'+markId+'" >сохранить</a>' +
          '&nbsp;&nbsp;<a href="#href" class="del-apartment-plan" id="del-apartment-plan-'+id+'-'+markId+'">удалить</a></div>';

        planId = 'plan-'+id;
        $('#'+planId).removeClass('floor-plan-image-active');
        $('#'+planId).append(htmlDialog);

        console.log(markId);
        if (apartmentsValue != '' && markId != null) {
          apartmentsObject = jQuery.parseJSON(apartmentsValue);
          i = 0;
          console.log(apartmentsObject);
          for (var obj in apartmentsObject[markId]) {
            console.log(apartmentsObject[markId][obj]);
            $('#apartment-number-'+i+'').val(apartmentsObject[markId][obj].apartment);
            $('#floor-number-'+i+'').val(apartmentsObject[markId][obj].floor);
            i++;
          }
        }
      }



      //Click Tracking Common Plan
      $(document).on('click', '.floor-plan-image-active', function(e){
        var offset = $(this).offset(), top, left, id;
        top = Math.ceil(100*(e.pageY -  offset.top)/$(this).height());
        left = Math.ceil(100*(e.pageX - offset.left)/$(this).width());

        id = $(this).attr('id').split('-');
        windowDialog(top, left, id[1], null);

      })


      //Saving mark
      $(document).on('click', '.save-apartment-plan', function(e){
        var i = 0,
            j = 0,
            id = $(this).attr('id').split('-'),
            apartment = $('#apartment-number-'+i),
            floor = $('#floor-number-'+i),
            windowDialog = $('.floor-window-dialog'),
            apartments = {},
            markApartments = new Array(),
            top,
            left,
            jsonApartments,
            plan = $('#plan-'+id[3]),
            apartmentsValue = $('#edit-field-plan-floor-und-'+id[3]+'-field-apartments-und-0-value').val(),
            place,
            apartmentsValueObj,
            home,
            lengthArr = 0;



        markApartments[lengthArr] = new Array();

        top = Math.ceil(100*(windowDialog.position().top)/plan.height());
        left = Math.ceil(100*(windowDialog.position().left)/plan.width());

        while(1) {
          apartment = $('#apartment-number-'+i);
          floor = $('#floor-number-'+i);

          if (apartment.val() != '' && floor.val() != '') {
            if (apartmentsValue.length > 0) {
              markApartments[i] = {
                apartment:apartment.val(),
                floor: floor.val(),
                top:top,
                left: left,
                home: home
              }
            }
            else {
              markApartments[lengthArr].push(
                apartments[i] = {
                  apartment:apartment.val(),
                  floor: floor.val(),
                  top:top,
                  left: left,
                  home: home
                }
              );
            }
          }
          else {
            break;
          }
          i++;
        }

        if (apartmentsValue.length > 0 ) {
          apartmentsValueObj = jQuery.parseJSON(apartmentsValue);
          console.log(id[4]);
          if (id[4] != 'null') {
            apartmentsValueObj[id[4]] = markApartments;
            lengthArr = id[4];
          }
          else {
            console.log(markApartments);
            apartmentsValueObj.push(markApartments);
            lengthArr = apartmentsValueObj.length-1;
          }
          jsonApartments = JSON.stringify(apartmentsValueObj);
          $('#edit-field-plan-floor-und-'+id[3]+'-field-apartments-und-0-value').val(jsonApartments);
        }
        else {
          jsonApartments = JSON.stringify(markApartments);
          $('#edit-field-plan-floor-und-'+id[3]+'-field-apartments-und-0-value').val(jsonApartments);
        }
        place = '<div class="mark mark-apartment" id="mark-'+id[3]+'-'+lengthArr+'" style="position: absolute; left:'+left+'%; top:'+top+'% ; z-index: 100;">'+lengthArr+'</div>';
        plan.append(place);
        $('.floor-window-dialog').remove();
        $('.tool-add').removeClass('tool-add-active');

      })

      $(document).on('click', '.mark-apartment', function(){
        var thisMark = $(this),
            markId = thisMark.attr('id').split('-'),
            top = thisMark.position('top'),
            left = thisMark.position('left'),
            plan = $('#plan-'+markId[1]);
            console.log(markId);

        top = Math.ceil(100*(thisMark.position().top)/plan.height());
        left = Math.ceil(100*(thisMark.position().left)/plan.width());

        windowDialog(top, left, markId[1], markId[2]);

      });


      $(document).on('click', '.del-apartment-plan', function(){
        var thisId = $(this).attr('id').split('-');
        if (thisId[4] != 'null') {
          var apartmentsValue = $('#edit-field-plan-floor-und-'+thisId[3]+'-field-apartments-und-0-value').val(),
              apartmentsObject = jQuery.parseJSON(apartmentsValue);
          apartmentsObject.splice(thisId[4],1);
          var jsonApartments = JSON.stringify(apartmentsObject);
          $('#edit-field-plan-floor-und-'+thisId[3]+'-field-apartments-und-0-value').val(jsonApartments);
          $('#mark-'+thisId[3]+'-'+thisId[4]).remove();
          $('.floor-window-dialog').remove();
        }


      });
    }
  }


}(jQuery));
