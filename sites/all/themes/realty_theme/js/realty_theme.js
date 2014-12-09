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

  Drupal.behaviors.realtySelectcomplex = {
    attach: $(function () {
      if( $('select[name="complex"]') == null) {
        complex_select();
      }
      $("#edit-developer").change(function () {
        complex_select();
      });
      function complex_select(){
        var complexSelect = $('select[name="complex"]');
        var developerSelect = $('select[name="developer"]');
        $.ajax({
          url: '/get_developer_complex',
          type: 'POST',
          data: {
            developer: developerSelect.val()
          },
          success: function(response) {
            complexSelect.html('');
            complexSelect.append(response);
          },
          error: function(response) {
            alert('false');
          }
        });
      }
    })
  };

}(jQuery));