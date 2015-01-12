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
        console.log(developerSelect);
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
        search_map($(this).val());
      });

      function search_map(category) {

        $.ajax({
          url: '/search_map',
          type: 'POST',
          data: {
            category: category
          },
          success: function(response) {

            var $search_map = $('#search-map');
            $search_map.html('');
            console.log(response);
            $search_map.html(response);
            Drupal.attachBehaviors($search_map, Drupal.settings);
          },
          error: function(response) {
            alert('false');
          }
        });
      }
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

}(jQuery));