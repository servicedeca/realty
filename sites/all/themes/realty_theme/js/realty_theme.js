(function ($) {

Drupal.behaviors.toursRangeSlider = {
  attach: $(function(){
    $(document).ready(function() {

      var owl = $("#owl-demo");

      owl.owlCarousel({
        items : 4, //10 items above 1000px browser width
        itemsDesktop : [1000,5], //5 items between 1000px and 901px
        itemsDesktopSmall : [900,3], // betweem 900px and 601px
        itemsTablet: [600,2], //2 items between 600 and 0
        itemsMobile : false // itemsMobile disabled - inherit from itemsTablet option
      });

      // Custom Navigation Events
      $(".next").click(function(){
        owl.trigger('owl.next');
      })
      $(".prev").click(function(){
        owl.trigger('owl.prev');
      })
      $(".play").click(function(){
        owl.trigger('owl.play',1000); //owl.play event accept autoPlay speed as second parameter
      })
      $(".stop").click(function(){
        owl.trigger('owl.stop');
      })

    });
  })
};
 Drupal.behaviors.realtyMultyselect = {
   attach: $(function() {
     $('#area').change(function() {
       console.log($(this).val());
     }).multipleSelect({
       width: '200px'
     });
     $('#masonry').change(function() {
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
      //if( $('select[name="complex"]') == ) {
      //  complex_select();
      //}
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

  Drupal.behaviors.realtyGetIdApartment = {
    attach: $(function () {
      $("#get-id-apartment").click(function () {
          alert('ok');
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