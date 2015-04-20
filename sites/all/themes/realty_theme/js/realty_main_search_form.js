(function ($) {

Drupal.behaviors.realtyFormSearch = {
  attach: $(function() {

    var multiple_select_form = function() {

//  date multiple select
      $(function() {
        $('#edit-field-home-deadline-quarter-value').change(function() {
        }).multipleSelect({
          placeholder: '',
          selectAllText: 'Отметить все',
          allSelected: 'Все'
        });
      });


//  wall type multiple select
      $(function() {
        $('#edit-field-masonry-value').change(function() {
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
        $('#edit-field-category-value').change(function() {
        }).multipleSelect({
          placeholder: '',
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
          console.log($(this).val());
          $('#edit-field-balcony-value [value=1]').attr('selected', false);
          $('#edit-field-loggia-value [value=1]').attr('selected', false);
          for (var i in $(this).val()) {
            console.log($(this).val()[i]);
            if ($(this).val()[i] == 0) {
              $('#edit-field-balcony-value [value=1]').attr('selected', 'selected');
            }
            if ($(this).val()[i] == 1)  {
              $('#edit-field-loggia-value [value=1]').attr('selected', 'selected');
            }
          }
        }).multipleSelect({
          placeholder: '',
          selectAllText: 'Отметить все',
          allSelected: 'Все'
        });
      });

    };

    multiple_select_form();
    $(document).ajaxSuccess(function() {
      multiple_select_form();
    });



    $(".sq").ionRangeSlider({
      hide_min_max: true,
      keyboard: true,
      min: 0,
      max: 200,
      postfix: "  м<sup>2</sup>",
      from: 30,
      to: 150,
      type: 'double',
      step: 1,
      grid: true
    });
    $(document).ready(function(){
      $('#edit-field-gross-area-value-min').val(30);
      $('#edit-field-gross-area-value-max').val(150);
    });
    $(".sq").change(function(){
      var sq =  $(this).val().split(';');
      $('#edit-field-gross-area-value-min').val(sq[0]);
      $('#edit-field-gross-area-value-max').val(sq[1]);
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

    $(document).ready(function(){
      $('#edit-field-price-value-min').val(55 * 1000);
      $('#edit-field-price-value-max').val(85 * 1000);
    });
    $(".price").change(function(){
      var price =  $(this).val().split(';'),
          priceMin = price[0]*1000,
          priceMax;
      price[1] == 100 ? priceMax = price[1] * 100000 :  priceMax = price[1] * 1000;
      $('#edit-field-price-value-min').val(priceMin);
      $('#edit-field-price-value-max').val(priceMax);
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

    $(document).ready(function() {
      $('#edit-field-full-cost-value-min').val(1.6 * 1000000);
      $('#edit-field-full-cost-value-max').val(4 * 1000000);
    });
    $(".coast").change(function(){
      var coast =  $(this).val().split(';'),
          coastMin = coast[0] * 1000000,
          coastMax;
      coast[1] == 5 ? coastMax = coast[1] * 100000000 : coastMax = coast[1] * 1000000;
      $('#edit-field-full-cost-value-min').val(coastMin);
      $('#edit-field-full-cost-value-max').val(coastMax);
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

    multiselect_modal('CheckboxArea', 'edit-field-area-tid', 'search-input-area');
    multiselect_modal('CheckboxRoom', 'edit-field-number-rooms-value', 'search-input-room');
    multiselect_modal('CheckboxDeveloper', 'edit-field-complex-developer-tid', 'search-input-developer');
    multiselect_modal('CheckboxMetro', 'edit-field-complex-metro-tid', 'search-input-metro');
    multiselect_modal('CheckboxComplex', 'edit-field-home-complex-target-id', 'search-input-complex');

    function complex_select(devid) {
      var city = Drupal.settings.city;
      $.ajax({
        url: '/get_developer_complex',
        type: 'POST',
        data: {
          developer: devid,
          city: city
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
        $('#edit-field-parking-value option[value=1]').attr('selected', 'selected')
      }
    });

  })
};

}(jQuery));