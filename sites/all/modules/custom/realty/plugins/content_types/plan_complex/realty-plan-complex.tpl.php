<div class="container fin">

  <div id="Complex-plan">
    <div class="col-xs-10 col-xs-offset-1 tab-menu zero-padding">
      <div class="col-xs-8 zero-padding">
        <div class="col-xs-4 tab-menu-active">
          <?php print t('overall plan');?>
        </div>
        <div class="col-xs-4 tab-menu-passive">
          <a href="#" class="not-allowed" title="Выберите дом">
           <?php print t('Sections');?>
          </a>
        </div>
        <div class="col-xs-4 tab-menu-passive">
          <a href="#" class="not-allowed" title="Выберите дом">
            <?php print t('Floors');?>
          </a>
        </div>
      </div>
    </div>
    <div class="col-xs-8 right-part-complex zero-padding">
      <?php if($homes):?>
        <?php foreach($homes as $home):?>
          <?php print $home['number']?>
        <?php endforeach?>
      <?php endif;?>
      <?php if($complex_plan):?>
        <?php print $complex_plan;?>
      <?php endif;?>
    </div>
    <div class="col-xs-4 left-part-complex zero-padding">
      <div class="vertical">
        <p>
          Новосибирск, Водопроводная, 1а
        </p>
        <p>
          Этажность: 9 – 20 этажей
        </p>
        <p>
          Первая очередь строительства: секции №1, №2, №3 II квартал 2013 г. – II квартал 2015 г
        </p>
        <p>
          Вторая очередь строительства: секции №4, №5, №6, №7, №8 III квартал 2014 г. – IV квартал 2016 г.
        </p>
      </div>
    </div>
  </div>

</div>