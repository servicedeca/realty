(function ($) {

 Drupal.behaviors.realtyMultyselect = {
   attach: $(function() {
     $('#area').change(function() {
       console.log($(this).val());
     }).multipleSelect({
       width: '200px'
     });
     $('#area-map').change(function() {
       console.log($(this).val());
     }).multipleSelect({
       width: '200px'
     });
     $('#masonry').change(function() {
       console.log($(this).val());
     }).multipleSelect({
       width: '200px'
     });
     $('#masonry-map').change(function() {
       console.log($(this).val());
     }).multipleSelect({
       width: '200px'
     });
     $('#category-map').change(function() {
       console.log($(this).val());
     }).multipleSelect({
       width: '200px'
     });
     $('#category').change(function() {
       console.log($(this).val());
     }).multipleSelect({
       width: '200px'
     });
     $('#room').change(function() {
       console.log($(this).val());
     }).multipleSelect({
       width: '200px'
     });
     $('#developer').change(function() {
       console.log($(this).val());
     }).multipleSelect({
       width: '200px'
     });
     $('#complex').change(function() {
       console.log($(this).val());
     }).multipleSelect({
       width: '200px'
     });
     $('#quarter').change(function() {
       console.log($(this).val());
     }).multipleSelect({
       width: '200px'
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
        var select = $('select[id="edit-field-category-value"]');;
        select.val($(this).val());
        $('#edit-submit-map').trigger('click');
      });
      $("#area-map").change(function () {
        var select = $('select[id="edit-field-area-tid"]');;
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

}(jQuery));