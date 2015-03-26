(function ($) {

  Drupal.behaviors.realtyFormSearch = {
  attach: $(function() {

    var apartmentStatus = function () {

      // при клике по диву, делаем проверку
      $(document).on('click','.dec_checkbox', function(){
        var checkbox = $(this).find('input[type=checkbox]');
        // если чекбокс был активен
        if(checkbox.prop("checked")){
          // снимаем класс с родительского дива
          $(this).removeClass("check_active");
          // и снимаем галочку с чекбокса
          checkbox.prop("checked", false);
          // если чекбокс не был активен
          $('#edit-field-status-value option[value=All]').attr('selected', 'selected');
          $('#edit-submit-apartments').trigger('click');
        }else{
          // добавляем класс родительскому диву
          $(this).addClass("check_active");
          // ставим галочку в чекбоксе
          checkbox.prop("checked", true);
          $('#edit-field-status-value option[value=1]').attr('selected', 'selected');
          $('#edit-submit-apartments').trigger('click');
        }
      });
    }

    var realtyInitForm = function () {
      var i,
          wall,
          coastMin,
          coastMax,
          priceMin,
          priceMax;


      $('.decor_checkbox').each(function(){
        var checkbox = $('#parking');
        if(checkbox.prop("checked")) $(this).addClass("check_active");
      });

      $('.decor_checkbox').click(function() {
        var checkbox = $('#parking');
        console.log(checkbox);
        if(checkbox.prop("checked")){
          $(this).removeClass("check_active");
          checkbox.prop("checked", false);
          checkbox.val(0);
          $('#edit-field-parking-value option[value=1]').attr('selected', false)
        }else {
          $(this).addClass("check_active");
          checkbox.prop("checked", true);
          checkbox.val(1);
          $('#edit-field-parking-value option[value=1]').attr('selected', 'selected');
        }
      });

      $('#wall_type')
        .change(function(){
          wall = $(this).val();
          $('#edit-field-masonry-value option:selected').each(function(){
            this.selected=false;
          });
          for (i in wall) {
            $('#edit-field-masonry-value option[value="'+wall[i]+'"]').attr('selected', 'selected');
          }
        })
        .multipleSelect({
        placeholder: '',
        selectAllText: 'Отметить все',
        allSelected: 'Все'
      });

      $('#cat')
        .change(function(){
          wall = $(this).val();
          $('#edit-field-category-value option:selected').each(function(){
            this.selected=false;
          });
          for (i in wall) {
            $('#edit-field-category-value option[value="'+wall[i]+'"]').attr('selected', 'selected');
          }
        })
        .multipleSelect({
        placeholder: '',
        selectAllText: 'Отметить все',
        allSelected: 'Все'
      });

      $('#date')
        .change(function(){
          wall = $(this).val();
          $('#edit-field-quarter-value option:selected').each(function(){
            this.selected=false;
          });
          for (i in wall) {
            $('#edit-field-quarter-value option[value="'+wall[i]+'"]').attr('selected', 'selected');
          }
        })
        .multipleSelect({
        placeholder: '',
        selectAllText: 'Отметить все',
        allSelected: 'Все'
      });

      $('#balkon')
        .change(function(){
          wall = $(this).val();
          $('#edit-field-balcony-value option[value="1"]').attr('selected', false);
          $('#edit-field-loggia-value option[value="1"]').attr('selected', false);
          for (i in wall) {
            if (wall[i] == 1) {
              $('#edit-field-balcony-value option[value="1"]').attr('selected', 'selected');
            }
            if (wall[i] == 2) {
            $('#edit-field-loggia-value option[value="1"]').attr('selected', 'selected');
            }
          }
        })
        .multipleSelect({
        placeholder: '',
        selectAllText: 'Отметить все',
        allSelected: 'Все'
      });

      $('#edit-year').change(function(){
        $('#edit-field-year-value').val($(this).val());
      });

      $('#floor').change(function(){
        $('#edit-field-apartment-floor-value').val($(this).val());
      });

      $(".sq").change(function(){
        wall = $(this).val();
        wall = wall.split(';');
        $('#edit-field-gross-area-value-min').val(wall[0]);
        $('#edit-field-gross-area-value-max').val(wall[1]);
      });

      $(".price").change(function(){
        wall = $(this).val();
        wall = wall.split(';');
        priceMin = wall[0] * 1000;
        wall[1] == 100 ? priceMax = wall[1] * 100000 :  priceMax = wall[1] * 1000;
        $('#edit-field-price-value-min').val(priceMin);
        $('#edit-field-price-value-max').val(priceMax);
      });

      $(".coast").change(function(){
        wall = $(this).val();
        wall = wall.split(';');
        coastMin = wall[0] * 1000000;
        wall[1] == 5 ? coastMax = wall[1] * 100000000 :  coastMax = wall[1] * 1000000;
        $('#edit-field-full-cost-value-min').val(coastMin);
        $('#edit-field-full-cost-value-max').val(coastMax);
      });

      $('#edit-submit').click(function(){
        $('#edit-submit-apartments').trigger('click');
      })


    }

    var realtyInitValueForm = function () {
      var i,
          n,
          areas = $('#edit-field-area-tid').val(),
          developers = $('#edit-field-complex-developer-tid').val(),
          complexes = $('#edit-field-home-complex-target-id').val(),
          rooms = $('#edit-field-number-rooms-value').val(),
          floor = $('#edit-field-apartment-floor-value').val(),
          masonry = $('#edit-field-masonry-value').val(),
          category = $('#edit-field-category-value').val(),
          quarter = $('#edit-field-quarter-value').val(),
          loggia = $('#edit-field-loggia-value').val(),
          balcony = $('#edit-field-balcony-value').val(),
          year = $('#edit-field-year-value').val(),
          sqMin = $('#edit-field-gross-area-value-min').val(),
          sqMax = $('#edit-field-gross-area-value-max').val(),
          priceMin = $('#edit-field-price-value-min').val() / 1000,
          priceMax = $('#edit-field-price-value-max').val() / 1000,
          coastMin = $('#edit-field-full-cost-value-min').val() / 1000000,
          coastMax = $('#edit-field-full-cost-value-max').val() / 1000000,
          parking = $('#edit-field-parking-value').val();

          console.log(coastMax);
      for (i in developers) {
        $('#id-developer-'+developers[i]).trigger('click');
      }
      for (i in areas) {
        $('#id-area-'+areas[i]).trigger('click');
      }
      for (i in complexes) {
        $('#id-complex-'+complexes[i]).trigger('click');
      }
      for (i in rooms) {
        $('#id-room-'+rooms[i]).trigger('click');
      }
      for (i in masonry) {
        n = masonry[i]-1;
        $('input[name="selectItemmasonry[]"]:eq('+n+')').trigger('click');
      }
      for (i in category) {
        n = category[i]-1;
        $('input[name="selectItemcategory[]"]:eq('+n+')').trigger('click');
      }
      for (i in quarter) {
        n = quarter[i]-1;
        $('input[name="selectItemquarter[]"]:eq('+n+')').trigger('click');
      }
      if (loggia == 1) {
        $('input[name="selectItembalcony[]"]:last').trigger('click');
      }
      if (balcony == 1) {
        $('input[name="selectItembalcony[]"]').trigger('click');
      }
      $('#edit-year').val(year);
      $('#floor').val(floor);
      $(".sq").ionRangeSlider({
        hide_min_max: true,
        keyboard: true,
        min: 0,
        max: 200,
        postfix: " т.р.",
        from: sqMin != 0 ? sqMin : 30 ,
        to: sqMax != 0 ? sqMax : 150,
        type: 'double',
        step: 1,
        grid: true,
        hasGrid: true
      });
      $(".price").ionRangeSlider({
        hide_min_max: true,
        keyboard: true,
        min: 40,
        max: 100,
        postfix: " т.р.",
        from: priceMin != 0 ? priceMin : 55,
        to: priceMax != 0 ? priceMax : 85,
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
        from: coastMin != 0 ? coastMin : 1.6,
        to: coastMax != 0 ? coastMax : 4,
        type: 'double',
        step: 0.2,
        grid: true,
        hasGrid: true
      });

      if (parking == 1) {
        $('.decor_checkbox span').trigger('click');
      }
    }

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
            //complex_select(devid);
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

    realtyInitForm();
    multiselect_modal('CheckboxArea', 'edit-field-area-tid', 'search-input-area');
    multiselect_modal('CheckboxRoom', 'edit-field-number-rooms-value', 'search-input-room');
    multiselect_modal('CheckboxDeveloper', 'edit-field-complex-developer-tid', 'search-input-developer');
    multiselect_modal('CheckboxMetro', 'edit-field-complex-metro-tid', 'search-input-metro');
    multiselect_modal('CheckboxComplex', 'edit-field-home-complex-target-id', 'search-input-complex');
    realtyInitValueForm();
    apartmentStatus();
  })
  };

}(jQuery));